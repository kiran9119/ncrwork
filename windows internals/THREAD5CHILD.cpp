#include<windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;
int _tmain(int argc, _TCHAR* argv[], TCHAR* env[])
{


	HANDLE handle = (HANDLE)(*argv[0]);
	cout << handle;
	SetPriorityClass(handle, BELOW_NORMAL_PRIORITY_CLASS);
	return 0;
}