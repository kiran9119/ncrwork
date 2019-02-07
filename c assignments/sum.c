#include<stdio.h>







int main()



{

	int n, sum = 0;

	printf("Enter a number");

	scanf_s("%d", &n);

	while (n > 0)

	{

		sum = sum + n % 10;

		n /= 10;

	}



	printf("%d", sum);









	getch();



	return 0;







}