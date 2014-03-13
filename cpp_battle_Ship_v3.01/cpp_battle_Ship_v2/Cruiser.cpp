#include "stdafx.h"
#include "Cruiser.h"


CCruiser::CCruiser(void)
{
	m_Name = "Cruiser";
	m_Type = CRUISER;
	m_HP = 3;
}


CCruiser::~CCruiser(void)
{
}

HITRESULT CCruiser::HitCheck(Position hitPos)
{
	HITRESULT result = CShip::HitCheck(hitPos);

	return(result ==DESTROY) ? DESTROY_CRUISER : result;
}