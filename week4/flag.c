/**
 * @file flag.c
 * @author Dongzhu Huang (z257526)
 * @brief Prints a flag, a modified version of COMP1521's week 4 tutorial's question 2.
 * @date 22T3
 */

#include <stdio.h>

#define NUM_ROWS 6
#define NUM_COLS 12

char flag[NUM_ROWS][NUM_COLS] = {
	{'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
	{'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
	{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
	{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
	{'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
	{'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'}
};

void printFlag(void);
void printRow(int row);
void printHill(int height);

int main(void)
{
	printFlag();

	// Prints the flag pole
	printf("|\n|\n|\n|\n|\n|\n|\n|\n");

	printHill(8);
}

/**
 * @brief Prints the flag. Just a for loop, printing is done in printRow().
 */
void printFlag(void)
{
	for (int row = 0; row < NUM_ROWS; row++) {
		printRow(row);
	}
}

/**
 * @brief Prints a single row of the flag.
 *
 * @param row The current row we're up to
 */
void printRow(int row)
{
	for (int col = 0; col < NUM_COLS; col++) {
		putchar(flag[row][col]);
	}
	putchar('\n');
}

/**
 * @brief Prints a triangular hill using recursion.
 *
 * @param height How high the pole should be
 */
void printHill(int height)
{
	// Terminating case
	if (height <= 0) {
		return;
	}


	// Recursive call
	printHill(height - 1);

	for (int i = 0; i < height; i++) {
		putchar('*');
	}
	putchar('\n');
}
