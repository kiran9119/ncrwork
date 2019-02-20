#include<iostream>
using namespace std;
class Add
{
	int real, imaginary;
  public:
	  Add()
	  {
		  real = 0;
		  imaginary = 0;
	  }

	  Add(int num)
	  {
		  real = imaginary = num;
	  }

	  Add(int num1, int num2)
	  {
		  real = num1;
		  imaginary = num2;
	  }

	  friend void ComplexAdd(Add a, Add b);
	  friend void ComplexMultiply(Add a, Add b);
};

void ComplexAdd(Add a, Add b) {
	cout << (a.real + b.real)<< "+"<<(a.imaginary + b.imaginary)<<"i"<<endl;
}

void ComplexMultiply(Add a, Add b) {
	int real_part = (a.real*b.real)+ (a.imaginary*b.imaginary*-1);
	int complex_part = (a.real*b.imaginary) +(a.imaginary*b.real);
	cout << real_part << "+" << complex_part << "i";
}

int main()
{
	Add one(1, 2), two(2, 3);
	ComplexAdd(one, two);
	ComplexMultiply(one, two);
	getchar();
	return 0;
}