#include "stdafx.h"
#include "Battleship.h"


CBattleship::CBattleship(void)
{
	m_Name = "Battleship";
	m_Type = BATTLESHIP;
	m_HP = 4;
}


CBattleship::~CBattleship(void)
{
}

HITRESULT CBattleship::HitCheck(Position hitPos)
{
	HITRESULT result = CShip::HitCheck(hitPos);

	return(result ==DESTROY) ? DESTROY_BATTLESHIP : result;
}