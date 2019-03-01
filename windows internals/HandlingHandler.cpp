#include<Windows.h>
#include<iostream>
#include<tchar.h>

using namespace std;
#define BUFFERSIZE 100


int _tmain(int argc, WCHAR *argv[], WCHAR* env[])
{
	HANDLE CreateFileHandler;
	
	_SECURITY_ATTRIBUTES SA;
	SA.bInheritHandle=TRUE;
	SA.nLength=sizeof(SA);
	SA.lpSecurityDescriptor = NULL;
	CreateFileHandler = CreateFile(argv[1],//name of the file which need to be accessed
		GENERIC_READ,//type of access required on the file wether read or write or anyone
		0,//shared mode if 0 indicates that the file cannot be accessed by other process
		&SA,//security attribute indicates that it cannot be inherited if the value is NULL
		CREATE_ALWAYS,//the indicator to tell wether a new file is to be created or an existing file need to be opened
		FILE_ATTRIBUTE_NORMAL,//flag
		NULL);
	
		if (CreateFileHandler == INVALID_HANDLE_VALUE)
		{
			cout << "handler initiation failed due to error code: " << GetLastError() << endl;//get the error code when any error has occured in creating file handler
			wcout << "failed to open file: " << argv[1] << endl;
		}
		else
		{
			STARTUPINFO s;
			PROCESS_INFORMATION p;
			ZeroMemory(&s, sizeof(s));
			ZeroMemory(&p, sizeof(p));
			s.cb = sizeof(s);
			
			BOOL var = CreateProcess(NULL,//function name
				argv[2],//process name 
				&SA,//PROCESS ATTRIBUTES
				NULL,
				FALSE,
				0,
				NULL,
				NULL,
				&s,
				&p);
			return 0;
			getchar();
		}
		}