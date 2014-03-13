#include "stdafx.h"
#include "GameManager.h"


CGameManager* CGameManager::m_ManagerInstance=NULL;


CGameManager::CGameManager(void)
{
}


CGameManager::~CGameManager(void)
{
}

void CGameManager::Run()
{
	float sum = 0;
	int games = 10;
	char msg[256] = {0,};
	std::string currentMap;

	for(int i = 0 ; i < games ; ++i){
		CPlayer* pAttacker = new CPlayer();
		CPlayer* pDefender = new CPlayer();

		pDefender->RandomArrangement();
		currentMap = pDefender->ShowMapInfo();

		CPrintToConsole::GetInstance()->PrintMessage(currentMap);

		int gameResult = pAttacker->StartAttack(pDefender);
		sum += (float)gameResult; 

		sprintf_s(msg,"gameResult = %d  sum = %f \n \n \n",gameResult,sum);
		//printf_s("gameResult = %d  sum = %f \n \n \n", gameResult, sum); 프린트 함수 MVC 모델 적용 작업
		CPrintToConsole::GetInstance()->PrintMessage(msg);

		//매니저 싱글톤 패턴을 활용한 배 파괴시 횟수 알림
		CGameManager::GetManagerInstance()->SetDestroyCount(0);

		delete pDefender;
		delete pAttacker;
	}
	printf_s("average : %f \n", sum/games);

}



CGameManager* CGameManager::GetManagerInstance()
{
	if(m_ManagerInstance==NULL)
	{
		m_ManagerInstance = new CGameManager();
	}

	return m_ManagerInstance;
}

void CGameManager::ManagerRelease()
{
	delete m_ManagerInstance;
	m_ManagerInstance = NULL;
}

/*
std::string CGameManager::GetDestroyCount(int num)
{
	std::string destroyCount;
	char temp[1];

	sprintf_s(temp,"%d",num);
	destroyCount += temp;

	return destroyCount;
}
*/