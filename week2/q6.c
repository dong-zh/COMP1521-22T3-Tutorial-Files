// Prints whether a number is small/big or medium
// COMP1521 week 2 question 6
// 22T3

#include <stdio.h>

int main(void)
{
	int x;
	printf("Enter a number: ");
	scanf("%d", &x);

	if (x > 100 && x < 1000) {
		printf("medium\n");
	} else {
		printf("small/big\n");
	}

	return 0;
}
