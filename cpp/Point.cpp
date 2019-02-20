#include<iostream>
#include<math.h>
using namespace std;
class point
{
	int x, y;
public:
	point() {
		x = y = 5;
	}

	point(int a, int b) {
		x = a;
		y = b;
	}
	friend int area(point a, point b);

};
 
int area(point a, point b)
{
	return pow((a.x - b.x),2) + pow((a.y - b.y),2);
}

int main()
{
	point p1(1, 2), p2(2, 3);
	cout << "Distance between p1 and p2 is" << area(p1, p2);
	int a;
	cin >> a;
	return 0;
}
