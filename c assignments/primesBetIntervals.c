#include<stdio.h>
int isprime(int n)
{
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	if (n % 2 == 0)
		return 0;
	int count = 0;
	for (int i = 3; i*i <= n; i = i + 1)
		if (n%i == 0)
			return 0;

	return 1;
}
int main()
{
	int x, y;
	scanf_s("%d %d", &x, &y);
	for (int i = x; i <= y; i++)
		if (isprime(i))
			printf("%d ", i);
	getch();
	return 0;

}