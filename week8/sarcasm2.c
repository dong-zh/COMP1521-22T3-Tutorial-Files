/**
 * @file sarcasm2.c
 * @author Dongzhu Huang
 * @brief Reads a text file and outputs a sarcastic version of it
 * @date 22T1
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <err.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	// arg check
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
		return EXIT_FAILURE;
	}

	char *inputFileName = argv[1];
	char *outputFileName = argv[2];

	FILE *inputFile = fopen(inputFileName, "r");
	if (inputFile == NULL) {
		err(EXIT_FAILURE, "can't open %s", inputFileName);
	}

	FILE *outputFile = fopen(outputFileName, "w");
	if (outputFile == NULL) {
		err(EXIT_FAILURE, "can't open %s", outputFileName);
	}

	bool lowercase = false;
	int c;

	while ((c = fgetc(inputFile)) != EOF) {
		if (lowercase) {
			fputc(tolower(c), outputFile);
		} else {
			fputc(toupper(c), outputFile);
		}

		lowercase = !lowercase;
	}

	fclose(inputFile);
	fclose(outputFile);
}
