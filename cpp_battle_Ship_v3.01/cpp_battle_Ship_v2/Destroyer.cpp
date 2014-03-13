#include "stdafx.h"
#include "Destroyer.h"


CDestroyer::CDestroyer(void)
{
	m_Name = "Destroyer";
	m_Type = DESTROYER;
	m_HP = 2;
}


CDestroyer::~CDestroyer(void)
{
}


HITRESULT CDestroyer::HitCheck(Position hitPos)
{
	HITRESULT result = CShip::HitCheck(hitPos);

	return(result ==DESTROY) ? DESTROY_DESTROYER : result;
}