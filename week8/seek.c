/**
 * @file seek.c
 * @author Dongzhu Huang
 * @brief Prints the word impostor from the innocent text file
 * @date 22T1
 */

#include <stdio.h>
#include <stdlib.h>
#include <err.h>

#define FILENAME "sus.txt"
#define OFFSET (22)
#define WORD_LENGTH (10)

int main(void)
{
	FILE *file = fopen(FILENAME, "r");
	if (!file) {
		err(EXIT_FAILURE, "can't open %s", FILENAME);
	}

	if (fseek(file, -OFFSET, SEEK_END) == -1) {
		err(EXIT_FAILURE, "failed to fseek %s", FILENAME);
	}

	for (int i = 0; i < WORD_LENGTH; i++) {
		putchar(fgetc(file));
	}
	putchar('\n');
}
