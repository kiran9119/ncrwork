#include<stdio.h>
#include<string.h>
void delete(char *s1, char c);
int main() {
	char s1[10], c;
	gets(s1);
	scanf_s("%c", &c);
	delete(s1, c);
	getch();
	return 0;
}

void delete(char *s2, char c)
{
	while (*s2 != '\0') {
		if (*s2 == c)
			*s2 = '';
		s2++;
	}

	printf("%s", s2);
}