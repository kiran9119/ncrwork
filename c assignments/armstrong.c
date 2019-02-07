#include<stdio.h>

#include<conio.h>



void main()

{

	int n, temp, rem = 0, sum = 0;

	printf("\nEnter a Number:");

	scanf("%d", &n);

	temp = n;

	while (temp != 0)

	{

		rem = temp % 10;

		sum = sum + (rem*rem*rem);

		temp = temp / 10;

	}

	if (sum == n)

	{

		printf("\nGiven Number : %d is an Armstrong Number", n);

	}

	else

	{

		printf("\nGiven Number : %d is not an Armstrong Number", n);

	}

	getch();

}