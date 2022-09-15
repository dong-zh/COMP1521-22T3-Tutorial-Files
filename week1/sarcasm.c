// Turns command line args into sarcastic casing
// Dongzhu Huang (z5257526)
// 22T3

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	// ./sarcasise 'hello world'
	// hElLo wOrLd
	// arg check
	if (argc != 2) {
		// should use fprintf() to print to stderr
		printf("Wrong number of args\n");
		return EXIT_FAILURE;
	}

	char *message = argv[1];

	for (int i = 0; i < strlen(message); i++) {
		char curr = message[i];

		if (i % 2 == 0) {
			// Even case
			printf("%c", tolower(curr));
		} else {
			// Odd case
			printf("%c", toupper(curr));
		}

	}
	printf("\n");

	return EXIT_SUCCESS;
}
