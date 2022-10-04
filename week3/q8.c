#include <stdio.h>

int main(void)
{
	int numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (int i = 0; i < 5; i++) {
		int x = numbers[i];
		int y = numbers[9 - i];

		numbers[i] = y;
		numbers[9 - i] = x;

		// numbers[3] = numbers[6];
		// int temp = numbers[6];
		// numbers[3] = temp;
	}
}
