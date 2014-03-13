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

	//ship 배치 부
	void		AddPosition(char x, char y);
	void		AddPosition(Position pos); // 오버로드
	

	//hitcheck 부
	virtual HITRESULT	HitCheck(Position hitPos);  //오버라이딩 
	HITRESULT	HitCheck(char x, char y); //오버로드
	

	//프로텍트 자료 빼내기
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