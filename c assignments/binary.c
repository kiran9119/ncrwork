#include<stdio.h>

#include<math.h>

int main()

{

	int n, i = -1, sum = 0;

	scanf_s("%d", &n);

	while (n > 0) {

		++i;

		if (n % 10 == 1)

			sum = sum + pow(2, i);

		n /= 10;



	}

	printf("%d", sum);

	getch();

	return 0;

}