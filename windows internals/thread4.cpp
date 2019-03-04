#include<windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;
int i;
DWORD WINAPI FUNC(LPVOID str)
{

	i++;
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
			0,//CREATION FLAG
			NULL);
		H1[1] = CreateThread(NULL,//Security attribute
			0,//Stack Size
			FUNC,//FUNCTION NAME
			NULL,//Function PArameter
			0,//CREATION FLAG
			NULL);
		WaitForMultipleObjects(2, H1, 1, INFINITE);
		cout << "the global i is: " << i << endl;
		if (i !=2)
		{
			cout << "inconsistent" << endl;
			break;
		}
	}
	getchar();

}