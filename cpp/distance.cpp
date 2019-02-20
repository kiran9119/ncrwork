#include<iostream>
using namespace std;
class Distance2;
class Distance1
{
	int metres, centimetres;
public:
	Distance1(int inputInM)
	{
		metres = inputInM;
		centimetres = metres * 100;
	}
	friend float resultInMetres(Distance1 d1, Distance2 d2);
	friend float resultInInches(Distance1 d1, Distance2 d2);
};

class Distance2
{
	int feet,inches;
public:
	Distance2(int inputInF)
	{
		feet = inputInF;
		inches = 12*feet;
	}

	friend float resultInMetres(Distance1 d1, Distance2 d2);
	friend float resultInInches(Distance1 d1, Distance2 d2);
};


float resultInMetres(Distance1 d1, Distance2 d2) {
	float metres =(float) 39.2 * d2.inches;
	return metres + d1.metres;
}

float resultInInches(Distance1 d1, Distance2 d2) {
	float inches = d1.metres / (39.2);
	return inches + d2.inches;
}


int main()
{
	Distance1 d1(1);
	Distance2 d2(1);
	cout << "Result Format \n1.Metres \n 2.Inches";
	int n;
	cin >> n;
	switch (n)
	{
	case 1: cout << resultInMetres(d1,d2);
		break;
	case 2: cout << resultInInches(d1, d2);
		break;
	}
	cin >> n;
	return 0;
}