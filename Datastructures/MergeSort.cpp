using namespace std;
#include<iostream>

void merge(int*,int, int, int);
void mergesort(int * arr,int low,int high)
{
	if (low < high) {
		int mid = (low + high-1) / 2;
		mergesort(arr,low,mid);
		mergesort(arr, mid + 1, high);
		merge(arr,low,mid,high);
	}
}

void merge(int *a,int low, int mid,int high)
{
	int s1, i = 0, k = 0, s2, e1, e2, *t, te = 0;

	s1 = low;

	e1 = mid;

	s2 = mid + 1;

	e2 = high;

	t = new int[high + 1];

	while (s1 <= e1 && s2 <= e2) {

		if (a[s1] < a[s2]) {

			t[te] = a[s1]; te++;

			s1++;

		}

		else {

			t[te] = a[s2]; te++;

			s2++;

		}

	}

	while (s1 <= e1)

	{

		t[te] = a[s1];

		s1++; te++;

	}

	while (s2 <= e2)

	{

		t[te] = a[s2];

		s2++; te++;

	}

	k = 0;

	for (i = low; i <= high; i++)

	{

		a[i] = t[k];

		k++;

	}

}

int main()
{ 
	int n,*arr;
	cout << "enter size of array\n";
	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	mergesort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout<< arr[i]<<" ";
	cin >> n;
	return 0;
}