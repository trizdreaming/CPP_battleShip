#include "stdafx.h"
#include "Submarine.h"


CSubmarine::CSubmarine(void)
{
	m_Name = "Submarine";
	m_Type = SUBMARINE;
	m_HP = 1;
}


CSubmarine::~CSubmarine(void)
{
}

HITRESULT CSubmarine::HitCheck(Position hitPos)
{
	HITRESULT result = CShip::HitCheck(hitPos);


	return(result ==DESTROY) ? DESTROY_SUBMARINE : result;
}