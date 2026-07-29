/**
 * @file seek.c
 * @author Dongzhu Huang
 * @brief Prints the word impostor from the text file
 * @date 23T2
 */

#include <stdio.h>
#include <stdlib.h>
#include <err.h>

#define FILENAME "sus.txt"
#define OFFSET (22)
#define WORD_LENGTH (8)

int main(void) {
	FILE *sus = fopen(FILENAME, "r");
	if (sus == NULL) {
		perror("failed to open sus.txt");
		return EXIT_FAILURE;
	}

	int ret = fseek(sus, -OFFSET, SEEK_END);
	if (ret == -1) {
		perror("failed to fseek");
		return EXIT_FAILURE;
	}

	for (int i = 0; i < WORD_LENGTH; i++) {
		putchar(fgetc(sus));
	}

	putchar('\n');
}
