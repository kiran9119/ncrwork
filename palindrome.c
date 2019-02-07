#include <stdio.h>
#include <string.h>

int is_palindrome(char str[]) {
	int i = 0, j = strlen(str) - 1;

	while (i < j) {
		char ch1 = str[i];
		char ch2 = str[j];

		if (ch1 != ch2) {
			return 0;
		}

		i++;
		j--;
	}

	return 1;
}
int main() {
	char s[] = "abbabba";

	if (is_palindrome(s)) {
		puts("Yes");
	}
	else {
		puts("No");
	}

	return 0
		;
}