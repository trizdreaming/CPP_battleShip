#pragma once
#include <string>

class CPrintToConsole
{
private:
	CPrintToConsole(void);

public:
	~CPrintToConsole(void);

public:
	void PrintMessage(std::string msg); //, bool newLine=true); 추가 인자를 넣는 부분(라인변경을 쉽게 가능)
	void PrintMessage(int num);

public: //싱글톤 메소드
	static CPrintToConsole* GetInstance();
	static void Release();


protected:
	static CPrintToConsole* m_pInstance; //싱글톤 객체
};

