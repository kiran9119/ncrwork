#include<iostream>
#include<string.h>
using namespace std;
class student
{
	char name[10];
	int average, marks1, marks2, marks3;
	
public:
	void setData(char *s,int m,int m2,int m3) {
		average = 0;
		strcpy_s(name, s);
		marks1 = m, marks2 = m2, marks3 = m3;
	}

	 void cal_average()
	{
		average= (marks1 + marks2 + marks3) / 3;
	}

	 void display()
	 {
		 cout <<"Student name:"<< name << " Marks :" << marks1 << " " << marks2 << " " << marks3 << " Average:" << average;
	}


};
int main() 
{
	student s1;
	s1.setData("akhil", 100, 98, 96);
	s1.cal_average();
	s1.display();
	getchar();
	return 0;

}