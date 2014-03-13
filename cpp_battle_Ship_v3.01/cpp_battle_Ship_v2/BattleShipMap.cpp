#include "stdafx.h"
#include "BattleShipMap.h"


CBattleShipMap::CBattleShipMap(void)
{
}


CBattleShipMap::~CBattleShipMap(void)
{
}

bool CBattleShipMap::IsVaild( Position pos )
{
	int posX = pos.x - 'A'; //pos.x 는 캐릭터 형이기 떄문에 ''안에 싸여져 있는 녀석들을 빼줘야 함
	int posY = pos.y - '1';

	if(posX<0 || posX>=MAP_SIZE || posY<0 || posY>=MAP_SIZE)
		return false;

	return true;
}

ShipType CBattleShipMap::GetMapInfo( Position pos )
{
	if(!IsVaild(pos))
		return NONE;

	int posX = pos.x - 'A';
	int posY = pos.y - '1';

	return m_mapInfo[posX][posY];
}

void CBattleShipMap::SetMapInfo( Position pos, ShipType shipType )
{
	int posX = pos.x - 'A';
	int posY = pos.y - '1';

	m_mapInfo[posX][posY] = shipType;

}

void CBattleShipMap::MapShipClear()
{
	for(int i =0 ; i<MAP_SIZE ; ++i){
		for(int j = 0 ; j<MAP_SIZE ; ++j){
			m_mapInfo[i][j] = EMPTY;
		}
	}
}

