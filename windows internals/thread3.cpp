#include<windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;
int i;
DWORD WINAPI FUNC(LPVOID str)
{

		cout << "i++=" << i++ << endl;
	//DWORD dwexitcode = 10;

	return 15;
}


int _tmain()
{
	HANDLE H1[1];
	while (1)
	{
		i = 0;
		H1[0] = CreateThread(NULL,//Security attribute
			0,//Stack Size
			FUNC,//FUNCTION NAME
			NULL,//Function PArameter
			CREATE_SUSPENDED,//CREATION FLAG
			NULL);
		H1[1] = CreateThread(NULL,//Security attribute
			0,//Stack Size
			FUNC,//FUNCTION NAME
			NULL,//Function PArameter
			CREATE_SUSPENDED,//CREATION FLAG
			NULL);
		WaitForMultipleObject(2, H1, 1, INFINITE);
		cout << "the global i is: " << i << endl;
		if (i == 1)
		{
			cout << "inconsistent" << endl;
			break;
		}
	}
	getchar();

}