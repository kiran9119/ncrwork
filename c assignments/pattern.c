#include<stdio.h>







int main()



{







	for (int i = 1; i <= 5; i++)



	{



		for (int j = 5; j >= 1; j--)



			if (i < j)



				printf(" ");



			else



				printf("%d", j);







		for (int j = 2; j <= 5; j++)



			if (j <= i)



				printf("%d", j);



		printf("\n");



	}











	getch();



	return 0;







}