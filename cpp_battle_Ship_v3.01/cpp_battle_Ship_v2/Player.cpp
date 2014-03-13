#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer(void)
{
	CAircraft*		aircraft = new CAircraft();
	CBattleship*	battleship = new CBattleship();
	CCruiser*		cruiser_1 = new CCruiser();
	CCruiser*		cruiser_2 = new CCruiser();
	CDestroyer*		destroyer_1 = new CDestroyer();
	CDestroyer*		destroyer_2 = new CDestroyer();
	//CSubmarine*		submarine_1 = new CSubmarine();
	//CSubmarine*		submarine_2 = new CSubmarine();

	m_Ships[0] = aircraft;
	m_Ships[1] = battleship;
	m_Ships[2] = cruiser_1;
	m_Ships[3] = cruiser_2;
	m_Ships[4] = destroyer_1;
	m_Ships[5] = destroyer_2;
	//m_Ships[5] = submarine_1;
	//m_Ships[6] = submarine_2;
	
	m_shipCounter = sizeof(m_Ships)/sizeof(m_Ships[0]);
}


CPlayer::~CPlayer(void)
{
	for(int i = 0 ; i< m_shipCounter ; ++i)
	{
		delete m_Ships[i];
		m_Ships[i] = NULL;
	}
}


HITRESULT CPlayer::HitCheck(Position hitPos)
{
	for(int i = 0 ; i < m_shipCounter ; ++i)
	{
		HITRESULT tempResult = m_Ships[i]->HitCheck(hitPos);
		if(tempResult != MISS)
		{
			return tempResult;
		}
	}
	return MISS;
}

bool CPlayer::CheckEndPoint()
{
	int sum = 0;
	for(int i = 0 ; i<m_shipCounter ; ++i)
	{
		int tempHp = m_Ships[i]->GetHPCURRENT();
		sum += tempHp;
	}

	if(sum<=0)
		return false;

	return true;
}

void CPlayer::RandomArrangement()
{
	m_Map.MapShipClear();

	Position rndPos;
	Position hitPos;
	Direction direction;
	bool checkFirstPosition = true;
		
	//int rndPickShip = rand()%m_shipCounter; 배를 랜덤으로 픽할 필요는 없으니깐 패스
	for(int i = 0 ; i < m_shipCounter ; ++i)
	{
		ShipType tempShipType = m_Ships[i]->GetType(); // 현재 배의 타입을 찾아 주는 것(지도 상 표시를 위해)
		int shipHPMax = m_Ships[i]->GetHPMAX(); //배의 최대 hp번 만큼 위치를 추가하기 위한 것

		do 
		{
			//초기 랜덤 좌표 생성
			int posX = rand()%MAP_SIZE;
			int posY = rand()%MAP_SIZE;
			rndPos.x = 'A'+posX;
			rndPos.y = '1'+posY;

			//랜덤 방향 생성 초기 랜점 좌표와 방향이 정상적인 경우, 특정 방향으로 char 값을 증가하도록 함
			direction = (rand() % 2 == 0) ? PORTRAITE : LANDSCAPE;

		} while (!CheckValid(direction, shipHPMax, rndPos));
			
		//실제 addposition
		for(int j = 0 ; j< shipHPMax ;++j)
		{
			hitPos.x = rndPos.x+((direction==LANDSCAPE) ? j : 0);
			hitPos.y = rndPos.y+((direction==PORTRAITE) ? j : 0);
			m_Ships[i]->AddPosition(hitPos);
			m_Map.SetMapInfo(hitPos, tempShipType);
		}	
	}
}

bool CPlayer::CheckValid( Direction rndDirection, int shipHPMax, Position rndPos )
{
	//유효성 체크. 유효성 체크 결과에 따라 addposition에 영향을 줄 수 있음을 생각할 것
	Position tempPos;

	for(int k = 0 ; k < shipHPMax ; ++k)
	{
		tempPos.x = rndPos.x + ((rndDirection == LANDSCAPE) ? k : 0);
		tempPos.y = rndPos.y + ((rndDirection == PORTRAITE) ? k : 0);
		if(m_Map.GetMapInfo(tempPos) != EMPTY)
		{
			return false;
		}
	}
	return true;
}


std::string CPlayer::ShowMapInfo()
{
	Position pos;
	ShipType tileInfo;
	std::string buffer; 
	char msg[256]={0,};
	

	sprintf_s(msg,"  1 2 3 4 5 6 7 8 \n");
	buffer += msg;

	for(int i =0 ; i<MAP_SIZE ; ++i)
	{
		sprintf_s(msg, "%C ", i+'A');
		buffer += msg;

		for(int j = 0 ; j<MAP_SIZE ; ++j)
		{
			pos.x = 'A' + i;
			pos.y = '1'+ j;
			tileInfo = m_Map.GetMapInfo(pos);

			switch (tileInfo)
			{
			case EMPTY:
				sprintf_s(msg,"E ");
				buffer += msg;
				break;
			case AIRCRAFT:
				sprintf_s(msg,"A ");
				buffer += msg;
				break;
			case BATTLESHIP:
				sprintf_s(msg,"B ");
				buffer += msg;
				break;
			case CRUISER:
				sprintf_s(msg,"C ");
				buffer += msg;
				break;
			case DESTROYER:
				sprintf_s(msg,"D ");
				buffer += msg;
				break;
			case SUBMARINE:
				sprintf_s(msg,"S ");
				buffer += msg;
				break;
			}
		}
		sprintf_s(msg,"\n");
		buffer += msg;
	}
	
	return buffer;
}

int CPlayer::StartAttack(CPlayer* pDefender)
{
	Position hitPos;

	int turn = 1;

	for (int i = 0 ; i < MAP_SIZE ; ++i)
	{
		for(int j = 0 ; j < MAP_SIZE ; ++ j)
		{
			hitPos.x = i + 'A';
			hitPos.y = j + '1';

			pDefender->HitCheck(hitPos);
			if(pDefender->CheckEndPoint()==false)
				break;

			turn ++;
		}

		if(pDefender->CheckEndPoint()==false)
			break;
	}

	return turn;
}




/*
순서대로 파괴하는 기본 공격은 의미 없음
		for (int i = 0 ; i < MAP_SIZE ; ++i)
		{
			for(int j = 0 ; j < MAP_SIZE ; ++ j)
			{
				hitPos.x = i + 'A';
				hitPos.y = j + '1';

				pDefender->HitCheck(hitPos);
				if(pDefender->CheckEndPoint()==false)
					break;
				
				turn ++;
			}
			if(pDefender->CheckEndPoint()==false)
				break;
		}
*/


/*
교수님 피드백 상 삭제, 추가로 오버라이딩할 경우 의미 없음
std::string CPlayer::getShipName(Position hitPos) {
	for(int i = 0 ; i < m_shipCounter ; ++i)
	{
		HITRESULT tempResult = ships[i]->HitCheck(hitPos);
		if(tempResult == DESTROY){
			m_retakeChecker = true;
			return ships[i]->GetName();
		}
	}
	return NULL;
}
*/

/*
void CPlayer::hitPosition()
{
	ships[0]->AddPosition('B','8');
	ships[0]->AddPosition('C','8');
	ships[0]->AddPosition('D','8');
	ships[0]->AddPosition('E','8');
	ships[0]->AddPosition('F','8');

	ships[1]->AddPosition('A','4');
	ships[1]->AddPosition('A','5');
	ships[1]->AddPosition('A','6');
	ships[1]->AddPosition('A','7');

	ships[2]->AddPosition('F','4');
	ships[2]->AddPosition('F','5');
	ships[2]->AddPosition('F','6');

	ships[3]->AddPosition('H','6');
	ships[3]->AddPosition('H','7');

	ships[4]->AddPosition('C','1');
	ships[4]->AddPosition('C','2');

	ships[5]->AddPosition('C','7');

	ships[6]->AddPosition('G','5');
}
*/