#include<stdio.h>

int main()

{

	int n,sum;

	scanf_s("%d %d", &n,&sum);

	int arr[100];

	for (int i = 0; i < n; i++)

		scanf_s("%d", &arr[i]);

	int temp = 0;

	for (int i = 0,k=0; i < n,k<n; i++) {

		temp = temp + arr[i];

		if (temp == sum) {

			printf("%d %d", k+1, i+1);

			break;

		}

		if(temp>sum) {

			temp = 0;

			k++;

			i = k;

			i--;

		}



	}

	getch();

	return 0;

}#include<stdio.h>

int main()

{

	int n,sum;

	scanf_s("%d %d", &n,&sum);

	int arr[100];

	for (int i = 0; i < n; i++)

		scanf_s("%d", &arr[i]);

	int temp = 0;

	for (int i = 0,k=0; i < n,k<n; i++) {

		temp = temp + arr[i];

		if (temp == sum) {

			printf("%d %d", k+1, i+1);

			break;

		}

		if(temp>sum) {

			temp = 0;

			k++;

			i = k;

			i--;

		}



	}

	getch();

	return 0;

}