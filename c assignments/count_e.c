#include<stdio.h>

int main()
{
	int count = 0;
	char * s[] = {
		"we will teach you how to ",
		"MovE a mountain",
		"LevEl a building",
		"erase the past",
		"Make a million" };

	int len = (sizeof(s)) / sizeof(*s);
	for (int i = 0; i < len; i++) {
		printf("%s\n", s[i]);
		char * p = s[i];
		while (*p != '\0')
		{
			if (*p == 'e' || *p == 'E') {
				count++;
				printf("%c", *p);
			}
			p++;
		}
		printf("%d\n", count);
	}
	printf("%d", count);
	getch();
	return 0;
}