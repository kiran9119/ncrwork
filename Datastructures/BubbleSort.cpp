using namespace std;
#include<iostream>
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}


void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

int main()
{
	cout << "Enter size of array\n";
	int n;
	cin >> n;
	int *arr = new int[n];
	cout << "Enter elements into array\n";
	for (int i = 0; i < n; i++)
		cin >> arr[i] ;
	bubbleSort(arr, n);
	cout << "Array after sorting\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] <<" ";
	cin >> n;
	return 0;

}