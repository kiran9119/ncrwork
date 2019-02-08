#include<stdio.h>
#include<string.h>
char *recurstr(char *);
char temp = 0;
int main()
{
	char s[100], len;
	char *p;
	printf("enter the string :");
	gets(s);
	len = strlen(s);
	p = s;
	len--;
	while (len >= 1)
	{
		p++;
		len--;
	}
	recurstr(s,p);
	printf("%s", s);
	return 0;
}