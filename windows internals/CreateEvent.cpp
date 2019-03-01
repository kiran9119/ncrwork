#include<tchar.h>
#include<iostream>
#include<windows.h>
using namespace std;
 void  _tmain()
{
HANDLE H1;//Create a Handler
H1 = CreateEvent(NULL,//default Security Attribute
				TRUE,//Manual reset
				FALSE,//initial State is non-signalled
				TEXT("WriteEvent"));//Object name
				getchar();

}