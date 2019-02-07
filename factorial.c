#include<stdio.h>

int factorial(int);

int main()

{

	int n;

	scanf_s("%d", &n);

	printf("%d", factorial(n));

	return 0;

}



int factorial(int n) {

	if (n == 0)

		return 1;

	return n*factorial(n - 1);

}