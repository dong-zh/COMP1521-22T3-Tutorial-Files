/**
 * @file sarcasm.c
 * @author Dongzhu Huang
 * @brief Reads a text file and outputs a sarcastic version of it
 * @date 22T1
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <err.h>
#include <stdbool.h>

// int errno

int main(int argc, char *argv[]) {

	if (argc != 3) {
		fprintf(stderr, "Usage: %s <inFile> <outFile>\n", argv[0]);
		return EXIT_FAILURE;
	}

	char *inFilePath = argv[1];
	char *outFilePath = argv[2];

	FILE *inFile = fopen(inFilePath, "r");
	FILE *outFile = fopen(outFilePath, "w");

	if (inFile == NULL) {
		// Something's gone wrong
		perror("failed to open file");
		return EXIT_FAILURE;
	}
	if (outFile == NULL) {
		// Something's gone wrong
		perror("failed to open file");
		return EXIT_FAILURE;
	}

	int c = 0;
	int counter = 0;
	while ((c = fgetc(inFile)) != EOF) {
		if (counter % 2 == 0) {
			// Make lowercase
			fputc(tolower(c), outFile);
		} else {
			// Make uppercase
			fputc(toupper(c), outFile);
		}

		counter++;
	}



	fclose(inFile);
	fclose(outFile);

	// printf("%s\n", inFilePath);


}
