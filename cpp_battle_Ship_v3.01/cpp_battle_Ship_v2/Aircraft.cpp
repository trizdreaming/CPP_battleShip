#include "stdafx.h"
#include "Aircraft.h"


CAircraft::CAircraft(void)
{
	m_Name = "Aircraft";
	m_Type = AIRCRAFT;
	m_HP = 5;
}


CAircraft::~CAircraft(void)
{
}

HITRESULT CAircraft::HitCheck(Position hitPos)
{
	HITRESULT result = CShip::HitCheck(hitPos);
	return(result ==DESTROY) ? DESTROY_AIRCRAFT : result;
}