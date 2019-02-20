#include<iostream>
using namespace std;
class sample
{
public:
	sample() {
		cout << "Inside Constructors of sample";

	}

	~sample() {
		cout << "Inside the Destructor of the program";
	}
};

int main()
{
	sample s;
	int n;
	cin >> n;

	return 0;
}