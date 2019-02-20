#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
void swap_value(int a, int b) {
	a = a + b;
	b = a - b;
	a = a - b;
}
void swap_ref(int &a, int &b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

int main() {
	cout << "Enter ur choice\n 1.swap by value\n 2.swap by reference";
	int n;
	cin >> n;
	switch (n)
	{
	case 1:cout << "Enter 2 number a and b";
		   int a, b;
		   cin >> a >> b;
		   swap_value(a, b);
		   cout << "Value of a and b after swap:" << "a:" << a << "b:" << b;
		   break;

	case 2:cout << "Enter 2 number a and b";
		int c, d;
		cin >> c >> d;
		swap_ref(c, d);
		cout << "Value of a and b after swap:" << "a:" << c << "b:" << d;
		break;

	}
	
	return 0;
}
