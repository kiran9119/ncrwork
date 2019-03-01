#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{
	//WCHAR c[] = L"abcd";
	CHAR a[] = "abcdefgh";
	//cout <<strlen(c);
	//BOOL result = IsTextUnicode(c,wcslen(c),NULL);
	//cout << result;
	int result = MultiByteToWideChar(CP_UTF8,0,a,strlen(a)+1,NULL,0);
	//cout<<result;
	WCHAR *c = new WCHAR[result];
	result=MultiByteToWideChar(CP_UTF8, 0, a, strlen(a) + 1, c, result);
	//cout << result;
	wcout << c<<endl;
	
	result = WideCharToMultiByte(CP_UTF8,0,c,-1,NULL,0,NULL,NULL);
	char *b = new char[result];
	result = WideCharToMultiByte(CP_UTF8, 0,c,wcslen(c)+1,b,result, NULL, NULL);
	LPWSTR * argv;
	argv=CommandLineToArgvW(GetCommandLine());.
	cout <<b;
	int n;
		cin >> n;
		return 0;
}