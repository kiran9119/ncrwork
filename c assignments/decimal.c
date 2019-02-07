#include<stdio.h>

#include<math.h>

int main()

{

	int n, i = 1, sum = 0;

	scanf_s("%d", &n);

	while (n > 0) {

		sum = n % 2 * i + sum;

		n /= 2;

		i *= 10;



	}

	printf("%d", sum);

	getch();

	return 0;

}