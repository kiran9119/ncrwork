#include<stdio.h>
int main()
{
	int n, arr[100], flag = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);
	int i = 0, k = 0;
	while (i < n) {
		if (arr[k] < 0)
			k++;
		if (arr[k] >0 && flag == 0)
		{
			flag = 1;
			i = k + 1;

		}

		if (flag == 1 && arr[i] > 0) {
			i++;
			continue;
		}

		if (flag == 1 && arr[i] < 0) {
			int temp = arr[k];
			arr[k] = arr[i];
			arr[i] = temp;
			k++;
			flag = 0;
			continue;
		}



	}
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	getch();
	return 0;
}