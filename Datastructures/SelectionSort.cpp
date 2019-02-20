using namespace std;
#include<iostream>

int findMin(int* arr,int n,int size)
{
	int index = n;
	int min = arr[index];

	for (int i = n; i < size; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
				index = i;
		}
		
	}
	return index;
}
int main()
{
	cout << "enter size\n";
	int *arr,n;
	cin >> n;
	arr = new int[n];
	cout << "enter elements of the array\n";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n - 1; i++)
	{
		int k = findMin(arr,i+1,n);
		if (arr[i] > arr[k])
		{
			int temp;
			temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
	cout << "elements after sorting\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cin >> n;
	return 0;
}