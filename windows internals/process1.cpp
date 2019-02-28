#include<Windows.h>
#include<iostream>
#include<tchar.h>
int main(int argc,_TCHAR* argv[])
{
STARTUPINFO s;
PROCESS_INFORMATION p;
ZeroMemory(s,sizeof(s));
ZeroMemory(p, sizeof(p));
s.cb=sizeof(s);
BOOL var = CreateProcess(NULL,//function name
						argv[1],//process name 
						NULL,//PROCESS ATTRIBUTES
						NULL,
						FALSE,
						0,
						NULL,
						NULL,
						&s,
						&p);
			return 0;
}
