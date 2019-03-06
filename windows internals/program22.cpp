#include<windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;
DWORD WINAPI FUNC(LPVOID str)
{
	for (BOOL i = 0; i<10; i++)
		cout << "i=" << i<<endl;

	return 0;
}


int _tmain()
{
	HANDLE H1[2];
	H1[0] = CreateThread(NULL,//Security attribute
		0,//Stack Size
		FUNC,//FUNCTION NAME
		NULL,//Function PArameter
		CREATE_SUSPENDED,//CREATION FLAG
		NULL);
	Sleep(5000);
	WaitForMultipleObject(2, H1, FALSE, 1000);
	H1[1] = CreateThread(NULL,//Security attribute
		0,//Stack Size
		FUNC,//FUNCTION NAME
		NULL,//Function PArameter
		CREATE_SUSPENDED,//CREATION FLAG
		NULL);
	Sleep(5000);
	ResumeThread(H1);
		WaitForMultipleObject(2,H1,TRUE, 1000);
	WaitForMultipleObject(2, H1, TRUE, INFINITE);
	////WaitForMultipleObject(2, H1, FALSE, INFINITE);
	WaitForMultipleObject(2, H1, FALSE, 2000);
		
	getchar();

}