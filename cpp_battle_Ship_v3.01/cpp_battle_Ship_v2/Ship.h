#pragma once
#include <string>
#include "PrintToConsole.h"

enum HITRESULT
{
	MISS,
	HIT,
	DESTROY,

	DESTROY_AIRCRAFT,
	DESTROY_BATTLESHIP,
	DESTROY_CRUISER,
	DESTROY_DESTROYER,
	DESTROY_SUBMARINE,
};


enum ShipType
{
	NONE,
	EMPTY,
	AIRCRAFT,
	BATTLESHIP,
	CRUISER,
	DESTROYER,
	SUBMARINE,
};

enum Direction
{
	PORTRAITE,
	LANDSCAPE,
};

class Position
{
public:
	char	x;		
	char	y;		
	bool	bHit;	
};

class CShip
{
public:
	CShip(void);
	virtual	~CShip(void);

	//ship ��ġ ��
	void		AddPosition(char x, char y);
	void		AddPosition(Position pos); // �����ε�
	

	//hitcheck ��
	virtual HITRESULT	HitCheck(Position hitPos);  //�������̵� 
	HITRESULT	HitCheck(char x, char y); //�����ε�
	

	//������Ʈ �ڷ� ������
	std::string	GetName() { return m_Name; }
	int			GetHPMAX() { return m_HP; }
	int			GetHPCURRENT() { return m_HPCurrent; }
	ShipType	GetType() { return m_Type; }


	

protected:
	int			m_HP;
	int			m_HPCurrent;
	std::string	m_Name;
	ShipType	m_Type;
	Position	m_Pos[5];
};


//void		PrintPosition();