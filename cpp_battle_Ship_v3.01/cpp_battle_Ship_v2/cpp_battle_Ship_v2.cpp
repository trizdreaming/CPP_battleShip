// cpp_battle_Ship_v2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
//#include <iostream>
//#include "Player.h"
//#include "Ship.h"
#include "GameManager.h"
#include "PrintToConsole.h"

//�޸� ���� üũ
#ifdef _DEBUG
#define new new(_CLIENT_BLOCK, __FILE__, __LINE__)
#endif


int _tmain(int argc, _TCHAR* argv[])
{
	//�޸� ���� üũ�� �ڵ�
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	
	srand((unsigned int)time(NULL));
	

	CGameManager autoPlay;
	autoPlay.Run();




	/*
	CPrintToConsole printUI;
	
	����Ͷ���� �� �ִ� ����Ʈ���ܼ� ����
	int turn = 33;
	char szMsg[16] = {0,};

	sprintf_s(szMsg, "TURN : %d", turn);   => szMsg = "TURN : %d", turn);

	printUI.PrintMessage(szMsg);
	*/

	//�̱��� �����ڵ�
	CPrintToConsole::Release();

	getchar();

	return 0;
}
	/* 
	AI Ȱ���� ���� ���� �ڵ� �ּ�ȭ

	CPlayer human1;
	int counterCheck = 1;
	Position hitPos;

	human1.RandomArrangement();
	human1.ShowMapInfo();

	while (true)
	{
		printf_s("<<�� %d ��>>\n \n", counterCheck);
		std::cout<<"�Է� ��ǥ�� �־��ּ��� \n"<< "����) A5, B4, G6\n"<< ">>" ;
		std::cin >>hitPos.x >> hitPos.y;
		
		HITRESULT hitcheck = human1.HitCheck(hitPos);

		switch (hitcheck)
		{
		case MISS:
			printf_s("%c%c ���� ����! �ٽ� ���! \n\n\n", hitPos.x, hitPos.y);
			break;
		case HIT:
			printf_s("%c%c Ÿ��!! �� �߰�!! \n\n\n", hitPos.x, hitPos.y);
			break;


//	�������̵����� �� �������� ����
		case DESTROY:
			if(human1.getRetakeChecker()==false){
				--leftShipCheck;
			}
			printf_s("%c%c, ��ħ!! \n\n\n", hitPos.x, hitPos.y);
			break;
//

		//�ڵ��� �ߺ��̶� ����������, �� ������ �ƴ� ������ Ȯ��
		//������ �� �� ����ȭ ��ų �� �ִ� ����� �ʿ���.

		case DESTROY_AIRCRAFT:
			printf_s("%c%c, AIRCRAFT ��ħ!! \n\n\n", hitPos.x, hitPos.y);
			break;

		case DESTROY_BATTLESHIP:
			printf_s("%c%c, BATTLE SHIP ��ħ!! \n\n\n", hitPos.x, hitPos.y);
			break;

		case DESTROY_CRUISER:
			printf_s("%c%c, CRUISER ��ħ!! \n\n\n", hitPos.x, hitPos.y);
			break;

		case DESTROY_DESTROYER:
			printf_s("%c%c, DESTROYER ��ħ!! \n\n\n", hitPos.x, hitPos.y);
			break;

		case DESTROY_SUBMARINE:
			printf_s("%c%c, SUBMARIN ��ħ!! \n\n\n", hitPos.x, hitPos.y);
			break;
		}

		//����� ���۵� ������ ���� 64���� ������ �ڵ����� ������
		//�߸��� �Է��� �ϴ� ��� ��� ó�� ����� �ұ�? 1st G5G �Է� ���� ��� G5�� �Է��ص� GG, 5G�� ����
		//������ ���̴� ��찡 �ִµ�? ó�� �����?
		++counterCheck;
		if(counterCheck>65){
			printf_s("you fail, at least 64 turn!");
			break;
		}

		bool checker = human1.CheckEndPoint();
		if(checker == true){
			printf_s("�¸��ϼ̽��ϴ�!!, ����� ������ %d �Դϴ�", counterCheck);
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