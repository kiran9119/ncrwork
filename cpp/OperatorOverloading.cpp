#include<iostream>
#include<string>
using namespace std;
class student
{
	//string name;
	int marks1, marks2, marks3, totalmarks;

public:
	student() {
		marks1 = 100, marks2 = 90, marks3 = 80;
	}

	friend istream& operator>> (istream &cin, student &s);
	friend ostream& operator<< (ostream &cout, student &s);

	friend void generate_results(student[] s,int n);
};

//friend void generate_results(student[] s, int n) {}

istream& operator >> (istream &in, student &s)
{
	cout << "Enter student details\n";
	cin >> s.marks1 >> s.marks2>>s.marks3;
	return in;
}

ostream& operator << (ostream &out, student &s)
{
	cout << "\nstudent marks  are: \n";
	cout << s.marks1 <<" "<< s.marks2 <<" "<< s.marks3;
	return out;
}

void generate_results(student[] &s, int n)
{
	for (int i = 0; i < n; i++)
		cout << s[i].marks1;
}


int main()
{
	student s[3];
	for (int i = 0; i < 3; i++)
		cin >> s[i];
	for (int i = 0; i < 3; i++)
		cout << s[i];
	int i;
	generate_results(s, 1);
	cin >>i;
	return 0;
}
