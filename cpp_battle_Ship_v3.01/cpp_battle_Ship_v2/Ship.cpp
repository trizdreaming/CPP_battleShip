#include "stdafx.h"
#include "Ship.h"
#include <string.h>
#include "GameManager.h"


CShip::CShip(void)
{
	m_HP	= 0;
	m_HPCurrent = 0;

	memset(m_Pos, 0, sizeof(Position) * 5);
}


CShip::~CShip(void)
{
}

void CShip::AddPosition(char x, char y)
{
	if(m_HPCurrent < m_HP)
	{
		Position pos;
		pos.x = x;
		pos.y = y;
		pos.bHit = false;

		m_Pos[m_HPCurrent] = pos;	
		++m_HPCurrent;
		
	}
}

void CShip::AddPosition(Position pos)
{
	AddPosition(pos.x, pos.y);
}

/*
void CShip::PrintPosition()
{
	for(int i = 0; i < m_HPCurrent; i++)
	{
		printf_s("%s Position[%d] - %c%c\n", m_Name.c_str(), i, m_Pos[i].x, m_Pos[i].y);
	}
}
*/

HITRESULT CShip::HitCheck(Position hitPos)
{
	int arraySize = sizeof(m_Pos) / sizeof(m_Pos[0]);

	for(int i = 0; i < arraySize; i++)
	{
		if(m_Pos[i].x == hitPos.x && m_Pos[i].y == hitPos.y)
		{
			if(m_Pos[i].bHit == true){
				return HIT;
			}

			else//(m_Pos[i].bHit == false)
			{
				m_Pos[i].bHit = true;
				--m_HPCurrent;
			}

			//return (m_HPCurrent <= 0) ? DESTROY : HIT; //각 배별로 부서지도록 만들어보자
			if(m_HPCurrent<=0)
			{
				int num = CGameManager::GetManagerInstance()->GetDestroyCount();
				CGameManager::GetManagerInstance()->SetDestroyCount(++num);

				CPrintToConsole::GetInstance()->PrintMessage(num);
				
				return DESTROY;
			}
			else
			{
				return HIT;
			}
		}
	}

	return MISS;
}

HITRESULT CShip::HitCheck( char x, char y )
{
	Position pos;
	pos.x = x;
	pos.y = y;

	return HitCheck(pos);
}

