#pragma once
#include "ship.h"
class CAircraft :
	public CShip
{
public:
	CAircraft(void);
	~CAircraft(void);

	HITRESULT	HitCheck(Position hitPos);
};

