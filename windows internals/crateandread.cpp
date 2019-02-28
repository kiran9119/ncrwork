#include<Windows.h>
#include<iostream>
#include<tchar.h>
#include<string.h>
#include<string>

using namespace std;
#define BUFFERSIZE 100

int _tmain(int argc, WCHAR* argv[],char* env[] )
{

	HANDLE CreateFileHandler;
	CreateFileHandler = CreateFile(argv[1],//e of the file which need to be accessed
		GENERIC_WRITE,//type of access required on the file wether read or write or anyone
		0,//shared mode if 0 indicates that the file cannot be accessed by other process
		NULL,//security attribute indicates that it cannot be inherited if the value is NULL
		1,//the indicator to tell wether a new file is to be created or an existing file need to be opened
		FILE_ATTRIBUTE_NORMAL,//flag
		NULL);
	if (CreateFileHandler == INVALID_HANDLE_VALUE)
	{
		cout << "handler initiation failed due to error code: " << GetLastError() << endl;//get the error code when any error has occured in creating file handler
		wcout << "failed to open file: "  << endl;
	}
	else
	{
		//WCHAR *OutBuffer=new WCHAR[BUFFERSIZE];
	
		DWORD NoOfBytesRead = 0;
		WCHAR OutBuffer[BUFFERSIZE]=TEXT("hi this is kiran");
		BOOL status;
		//cout<<"enter the string";
		//string input;
		//getline(cin,input);
		status = WriteFile(CreateFileHandler//handler that has been created using create file
			, OutBuffer//output buffer pointer
			, BUFFERSIZE//size of the bytes to be read
			, &NoOfBytesRead//pointer of number of bytes read
			, NULL);
		if (status)//if status is 1 it means contents of file are read
		
		{
		
			_tprintf(_T("the file contents of the file: are %S "),  OutBuffer);//print the contents of file
			}

		else//file reading failed due to some error
		{
			cout << "error in writing the contents of file due to error: " << GetLastError() << endl;
			wcout << "error writing the file " << endl;
		}
	}
	CloseHandle(CreateFileHandler);
	int n;
	cin>>n;
	return 0;
	}