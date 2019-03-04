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
	HANDLE H1;
	H1 = CreateThread(NULL,//Security attribute
		0,//Stack Size
		FUNC,//FUNCTION NAME
		NULL,//Function PArameter
		CREATE_SUSPENDED,//CREATION FLAG
		NULL);
	Sleep(5000);
	ResumeThread(H1);//it resumes thread
		WaitForSingleObject(H1, INFINITE);
	getchar();

}