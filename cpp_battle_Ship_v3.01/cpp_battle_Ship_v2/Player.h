#pragma once


#include "Ship.h"
#include "BattleShipMap.h"
#include <iostream>
#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Submarine.h"
#include <time.h>

class CPlayer
{
public:
	CPlayer(void);
	~CPlayer(void);

	//void		SetPosition();
	HITRESULT	HitCheck(Position hitPos);
	std::string getShipName(Position hitPos);

	//���� ���� ����
	bool		CheckEndPoint();

	//����ڿ� �Լ� (������ġ �� ǥ��)
	void		RandomArrangement();
	bool		CheckValid(Direction rndDirection, int shipHPMax, Position rndPos);
	std::string	ShowMapInfo();


	//�����ڿ� �Լ�
	int			StartAttack(CPlayer* pDefender);

private:

	CShip* m_Ships[6];
	int m_shipCounter;
	CBattleShipMap m_Map;
	
	int m_largeAreaChanceDenominator;
	int m_largeAreaParityChecked_1;
	int m_largeAreaParityChecked_2;
	int m_largeAreaParityChecked_3;
	int m_largeAreaParityChecked_4;

	int m_centerAreaChanceDenominator;
	int m_centerAreaParityChecked;
};

