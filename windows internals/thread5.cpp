#include<Windows.h>
#include<iostream>
#include<tchar.h>
#include<tchar.h>
using namespace std;
int _tmain(int argc, _TCHAR* argv[], TCHAR* env[])
{

	STARTUPINFO s1, s2;
	PROCESS_INFORMATION p1, p2;
	ZeroMemory(&s1, sizeof(s1));
	ZeroMemory(&p1, sizeof(p1));
	s1.cb = sizeof(s1);
	_SECURITY_ATTRIBUTES SA;
	SA.bInheritHandle = TRUE;
	SA.nLength = sizeof(SA);
	SA.lpSecurityDescriptor = NULL;
	
	BOOL var = CreateProcess(NULL,//function name
		argv[1],//process name 
		&SA,//PROCESS ATTRIBUTES
		NULL,
		TRUE,
		HIGH_PRIORITY_CLASS,
		NULL,
		NULL,
		&s1,
		&p1);
	WCHAR handle[] = { (WCHAR)p1.hProcess };
	BOOL var1 = CreateProcess(argv[2],//function name
		handle,//process name 
		&SA,//PROCESS ATTRIBUTES
		NULL,
		TRUE,
		HIGH_PRIORITY_CLASS,
		NULL,
		NULL,
		&s1,
		&p1);
	getchar();
}