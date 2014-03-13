#pragma once
#include "Ship.h"

#define MAP_SIZE 8

class CBattleShipMap
{
public:
	CBattleShipMap(void);
	~CBattleShipMap(void);

	ShipType GetMapInfo(Position pos);
	void SetMapInfo(Position pos, ShipType shipType);
	

	//�ʱ�ȭ �Լ�
	void MapShipClear();

protected:
	bool IsVaild(Position pos);

protected:
	ShipType m_mapInfo[MAP_SIZE][MAP_SIZE];
};

