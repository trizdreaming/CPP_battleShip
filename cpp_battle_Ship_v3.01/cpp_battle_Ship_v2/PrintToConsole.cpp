#include "stdafx.h"
#include "PrintToConsole.h"

CPrintToConsole* CPrintToConsole::m_pInstance = NULL;
//extern 후 선언하는 것과 동일한 형태

CPrintToConsole::CPrintToConsole(void)
{
}


CPrintToConsole::~CPrintToConsole(void)
{
}

void CPrintToConsole::PrintMessage( std::string msg) //, bool newLine)
{
	/*
	if(newLine)
		printf_s("%s\n", msg);
	else
	{}
	*/
		printf_s("%s \n", msg.c_str());
}

void CPrintToConsole::PrintMessage( int num )
{
	char temp[16];
	std::string msg;

	sprintf_s(temp,"%d",num);

	for(int i=0 ; i < 16 ; ++i)
	{
		msg +=temp[i];
	}

	PrintMessage(msg);

}

CPrintToConsole* CPrintToConsole::GetInstance() //싱글톤 관련 함수
{
	if(m_pInstance == NULL)
	{
		m_pInstance = new CPrintToConsole();
	}

	return m_pInstance;
}

void CPrintToConsole::Release()
{
	if(m_pInstance)
	{
		delete m_pInstance;
		m_pInstance = NULL;
	}
}
