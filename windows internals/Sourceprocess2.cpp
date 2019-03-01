#include<Windows.h>
#include<iostream>
#include<tchar.h>
int _tmain(int argc, _TCHAR* argv[],TCHAR* env[])
{
	STARTUPINFO s1, s2;
	PROCESS_INFORMATION p1, p2;
	ZeroMemory(&s1, sizeof(s1));
	ZeroMemory(&p1, sizeof(p1));
	ZeroMemory(&s2, sizeof(s2));
	ZeroMemory(&p2, sizeof(p2));
	s1.cb = sizeof(s1);
	s2.cb = sizeof(s2);
	BOOL var = CreateProcess(NULL,//function name
		argv[1],//process name 
		NULL,//PROCESS ATTRIBUTES
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&s1,
		&p1);
		WaitForSingleObject(p1.hProcess,INFINITE);
	BOOL var1 = CreateProcess(NULL,//function name
		argv[2],//process name 
		NULL,//PROCESS ATTRIBUTES
		NULL,
		FALSE,
	0,
		NULL,
		NULL,
		&s2,
		&p2);
	getchar();
	return 0;
}
