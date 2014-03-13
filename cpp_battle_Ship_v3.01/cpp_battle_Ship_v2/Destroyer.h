#pragma once
#include "ship.h"
class CDestroyer :
	public CShip
{
public:
	CDestroyer(void);
	~CDestroyer(void);

	HITRESULT	HitCheck(Position hitPos);
};

