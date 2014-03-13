// cpp_battle_Ship_v2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
//#include <iostream>
//#include "Player.h"
//#include "Ship.h"
#include "GameManager.h"
#include "PrintToConsole.h"

//메모리 누수 체크
#ifdef _DEBUG
#define new new(_CLIENT_BLOCK, __FILE__, __LINE__)
#endif


int _tmain(int argc, _TCHAR* argv[])
{
	//메모리 누수 체크용 코드
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	
	srand((unsigned int)time(NULL));
	

	CGameManager autoPlay;
	autoPlay.Run();




	/*
	CPrintToConsole printUI;
	
	모니터라고할 수 있는 프린트투콘솔 연결
	int turn = 33;
	char szMsg[16] = {0,};

	sprintf_s(szMsg, "TURN : %d", turn);   => szMsg = "TURN : %d", turn);

	printUI.PrintMessage(szMsg);
	*/

	//싱글콘 해제코드
	CPrintToConsole::Release();

	getchar();

	return 0;
}
	/* 
	AI 활용을 위한 기존 코드 주석화

	CPlayer human1;
	int counterCheck = 1;
	Position hitPos;

	human1.RandomArrangement();
	human1.ShowMapInfo();

	while (true)
	{
		printf_s("<<제 %d 턴>>\n \n", counterCheck);
		std::cout<<"입력 좌표를 넣어주세요 \n"<< "예시) A5, B4, G6\n"<< ">>" ;
		std::cin >>hitPos.x >> hitPos.y;
		
		HITRESULT hitcheck = human1.HitCheck(hitPos);

		switch (hitcheck)
		{
		case MISS:
			printf_s("%c%c 공격 실패! 다시 쏘세요! \n\n\n", hitPos.x, hitPos.y);
			break;
		case HIT:
			printf_s("%c%c 타격!! 적 발견!! \n\n\n", hitPos.x, hitPos.y);
			break;


//	오버라이딩으로 각 함정별로 분할
		case DESTROY:
			if(human1.getRetakeChecker()==false){
				--leftShipCheck;
			}
			printf_s("%c%c, 격침!! \n\n\n", hitPos.x, hitPos.y);
			break;
//

		//코드의 중복이라 걱정했으나, 본 내용은 아닌 것으로 확인
		//하지만 좀 더 최적화 시킬 수 있는 방법이 필요함.

		case DESTROY_AIRCRAFT:
			printf_s("%c%c, AIRCRAFT 격침!! \n\n\n", hitPos.x, hitPos.y);
			break;

		case DESTROY_BATTLESHIP:
			printf_s("%c%c, BATTLE SHIP 격침!! \n\n\n", hitPos.x, hitPos.y);
			break;

		case DESTROY_CRUISER:
			printf_s("%c%c, CRUISER 격침!! \n\n\n", hitPos.x, hitPos.y);
			break;

		case DESTROY_DESTROYER:
			printf_s("%c%c, DESTROYER 격침!! \n\n\n", hitPos.x, hitPos.y);
			break;

		case DESTROY_SUBMARINE:
			printf_s("%c%c, SUBMARIN 격침!! \n\n\n", hitPos.x, hitPos.y);
			break;
		}

		//사용자 오작동 방지를 위해 64턴이 지나면 자동으로 중지됨
		//잘못된 입력을 하는 경우 어떻게 처리 해줘야 할까? 1st G5G 입력 이후 계속 G5를 입력해도 GG, 5G로 인지
		//순서가 꼬이는 경우가 있는데? 처리 방법은?
		++counterCheck;
		if(counterCheck>65){
			printf_s("you fail, at least 64 turn!");
			break;
		}

		bool checker = human1.CheckEndPoint();
		if(checker == true){
			printf_s("승리하셨습니다!!, 당신의 최종턴 %d 입니다", counterCheck);
			break;
		}
	}
	*/



/*

printf_s("%s is HP: %d, TYPE: %d\n\n", aircraft.GetNAME().c_str(), aircraft.GetHP(), aircraft.GetTYPE());
printf_s("%s is HP: %d, TYPE: %d\n\n", battleship.GetNAME().c_str(), battleship.GetHP(), battleship.GetTYPE());
printf_s("%s is HP: %d, TYPE: %d\n\n", cruiser.GetNAME().c_str(), cruiser.GetHP(), cruiser.GetTYPE());
printf_s("%s is HP: %d, TYPE: %d\n\n", destroyer01.GetNAME().c_str(), destroyer01.GetHP(), destroyer01.GetTYPE());
printf_s("%s is HP: %d, TYPE: %d\n\n", destroyer02.GetNAME().c_str(), destroyer02.GetHP(), destroyer02.GetTYPE());
printf_s("%s is HP: %d, TYPE: %d\n\n", submarine01.GetNAME().c_str(), submarine01.GetHP(), submarine01.GetTYPE());
printf_s("%s is HP: %d, TYPE: %d\n\n", submarine02.GetNAME().c_str(), submarine02.GetHP(), submarine02.GetTYPE());

aircraft.AddPosition('A','1');
aircraft.AddPosition('A','2');
aircraft.AddPosition('A','3');
aircraft.AddPosition('A','4');
aircraft.AddPosition('A','5');

aircraft.PrintPosition();
battleship.PrintPosition();

*/