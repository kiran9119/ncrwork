#include<iostream>
using namespace std;
class polar
{
	int angle, radius;
	

public:
	static int counter;
	polar()
	{
		counter++;
	}

	polar(int ang, int rad)
	{
		counter++;
		angle = ang;
		radius = rad;

	}

	 int getObjectCount()
	{
		return counter;
	}

};

int polar::counter;

int main()
{
	polar p, p1(1, 2), p3(4, 7);
	cout << "Total number of active objects of the class are " << p.getObjectCount();
	int n;
	cin >> n;
	return 0;
}