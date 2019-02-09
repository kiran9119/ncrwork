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

void delete(char *s1, char c)
{

	char * s2 = s1;
	while (*s1 != '\0') {
		if (*s1 == c) {
			char * ref = s1;
			while (*ref != '\0') {
				*ref = *(ref + 1);
				ref++;
			}
		}
		//printf("%c", *s1);
		s1++;
	}
	printf("%s", s2);

}