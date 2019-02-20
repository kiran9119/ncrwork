using namespace std;
#include<iostream>
int main()
{
	cout << "enter size\n";
	int *arr, n;
	cin >> n;
	arr = new int[n];
	cout << "enter elements of the array\n";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 1; i < n; i++)
	{
		int temp = arr[i];
		for (int j = i - 1; j >= 0; j--)
			if (arr[j] > temp) {
				arr[j + 1] = arr[j];

				if (j == 0)
				{
					arr[j] = temp;
					break;
				}
			}

			else
			{

				arr[j + 1] = temp;
				break;
			}
	}
	cout << "elements after sorting\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cin >> n;
	return 0;
}