#pragma once
#include "ship.h"
class CBattleship :
	public CShip
{
public:
	CBattleship(void);
	~CBattleship(void);

	HITRESULT	HitCheck(Position hitPos);
};

