// Prints a triangle
// COMP1521 week 2 question 8
// 22T3

#include <stdio.h>

int main(void)
{
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < i; j++) {
			putchar('*');
		}
		putchar('\n');
	};
	return 0;
}
