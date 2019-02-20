#include<iostream>
#include<string.h>
using namespace std;
inline int addittion(int a, int b) {
	return a + b;
}

inline int subtraction(int a, int b) {
	return a - b;
}

inline int multiplication(int a, int b) {
	return a * b;
}

inline int divide(int a, int b) {
	cout << a / b;
	return a / b;
}


int main()
{
	int a, b;
	cout << "Enter two numbers\n";
	cin >> a >> b;
	int n;
	cout << "Enter your choice \n 1.addittion \n 2.subtraction \n 3.multiplication \n 4.division\n";
	cin >> n;
	switch (n) {
	case 1:cout << addittion(a, b);
		   break;
	case 2:cout << subtraction(a, b);
		   break;
	case 3: cout << multiplication(a, b);
		   break;
	case 4: cout << divide(a, b);
		   break;
	}
	cin >> a;
	//_Sleep(20);
	return 0;
}