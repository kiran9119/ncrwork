#include<stdio.h>

int main()

{

	int n, sum = 0, i = 1;

	scanf_s("%d", &n);

	while (n > 0)

	{

		sum = sum * 10;

		sum = sum + n % 10;;

		n /= 10;



	}

	printf("%d", sum);

	getch();

	return 0;

}