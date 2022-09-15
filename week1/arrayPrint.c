// Prints 10 numbers in an array
// 22T3
// Dongzhu Huang

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH (10)

void printArrayI(int array[], int length);
void printArrayR(int array[], int indexToPrint, int length);

int main(void)
{
	// Numbers to print
	int numbers[ARRAY_LENGTH] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

	printArrayR(numbers, 0, ARRAY_LENGTH);


	printf("MAIN DONE!!!\n");
	return 0;
}

// Recursive function
void printArrayR(int array[], int indexToPrint, int length)
{
	// Terminating case
	if (indexToPrint == length) {
		return;
	}

	// Recursive call
	printArrayR(array, indexToPrint + 1, length);

	// Doing the print after the recursive call makes it print backwards
	printf("%d\n", array[indexToPrint]);
}

/**
 * @brief Prints an array
 *
 * @param array the array to print
 * @param length the length of the array
 */
void printArrayI(int array[], int length)
{
	for (int i = 0; i < length; i++) {
		printf("%d\n", array[i]);
	}
}
