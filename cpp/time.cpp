#include<iostream>
#include<string.h>
using namespace std;
class Time{
	int hours, minutes, seconds;
    public:
		Time() {
		}
		Time(int all) {
			hours = minutes = seconds = all;
		}

		Time(int h, int m, int s)
		{
			hours = h;
			minutes = m;
			seconds = s;
		}

		void display() {
			cout <<hours << ":" <<minutes << ":" <<seconds;
		}

		void add(Time &obj, Time &obj2) {
			 seconds = obj.seconds + obj2.seconds;
			 minutes=  obj.minutes + obj2.minutes;
			 hours = obj.hours + obj2.hours;
			 display();
		}
};

int main()
{
	Time t1(1, 2, 3),t2(1,2,3);
	t1.add(t1,t2);
	getchar();
	return 0;

}