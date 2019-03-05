#include<windows.h>
#include<iostream>
#include<tchar.h>
#include<stdio.h>
using namespace std;
LONG var;
CRITICAL_SECTION ca;
DWORD WINAPI FUNC(LPVOID str)
{

	EnterCriticalSection(&ca);//it enters the critical section
	var++;
	LeaveCriticalSection(&ca);//leaves the critical section
	return 0;

}

int _tmain()
{


	HANDLE H1[1];
	while (1)
	{
		var = 0;
		InitializeCriticalSection(&ca);//it initilize the critical section and it is used for parallel execution
		//InitializeCriticalSectionAndSpinCount(&ca,2000) here this function also tal=kes the sleep value 
	
		H1[0] = CreateThread(NULL,//Security attribute
			0,//Stack Size
			FUNC,//FUNCTION NAME
			NULL,//Function PArameter
			0,//CREATION FLAG
			NULL);
		H1[1] = CreateThread(NULL,//Security attribute
			0,//Stack Size
			FUNC,//FUNCTION NAME
			NULL,//Function PArameter
			0,//CREATION FLAG
			NULL);
		WaitForMultipleObjects(2, H1, 1, INFINITE);
		cout << "the global i is: " << var << endl;
		if (var != 2)
		{
			cout << "inconsistent" << endl;
			break;
		}
	}
	getchar();


}