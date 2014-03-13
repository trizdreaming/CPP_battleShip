#pragma once
#include <string>

class CPrintToConsole
{
private:
	CPrintToConsole(void);

public:
	~CPrintToConsole(void);

public:
	void PrintMessage(std::string msg); //, bool newLine=true); �߰� ���ڸ� �ִ� �κ�(���κ����� ���� ����)
	void PrintMessage(int num);

public: //�̱��� �޼ҵ�
	static CPrintToConsole* GetInstance();
	static void Release();


protected:
	static CPrintToConsole* m_pInstance; //�̱��� ��ü
};

