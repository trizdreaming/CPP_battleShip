#pragma once
#include "Player.h"
#include "PrintToConsole.h"

class CGameManager
{
public:
	CGameManager(void);
	~CGameManager(void);

	void Run();

	//½Ì±ÛÅæ °ü·Ã ÇÔ¼ö
public:
	static CGameManager* GetManagerInstance();
	static void ManagerRelease();

	void SetDestroyCount(int num){m_DestoryCount=num;}
	int GetDestroyCount(){return m_DestoryCount;}

protected:
	int m_DestoryCount;
	static CGameManager* m_ManagerInstance;

	//CPrintToConsole::GetInstance()
};

