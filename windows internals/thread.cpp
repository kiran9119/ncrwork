#include<windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;
DWORD WINAPI FUNC(LPVOID str)
{
	cout<< "function called";
	return 0;
}

int _tmain()
{
	HANDLE H1;
	H1 = CreateThread(NULL,//Security attribute
		0,//Stack Size
		FUNC,//FUNCTION NAME
		NULL,//Function PArameter
		0,//CREATION FLAG
		NULL);
	WaitForSingleObject(H1, INFINITE);
		getchar();

}