#include<iostream>
using namespace std;
class Employee
{
	int empid, salary;
	char name[10];

public:
	friend istream& operator>>(istream &in, Employee &e);

	int getSalary()
	{
		return salary;
	}

	char* getName()
	{
		return name;
	}
	
};


istream& operator>> (istream &in, Employee &e) {
	cin >>e.name >> e.empid >> e.salary;
	return in;
}


int main()
{
	Employee s[5];
	for (int i = 0; i < 5; i++)
		cin >> s[i];
	cout <<s[0].getName();
	int k;
	cin >> k;
	return 0;

}