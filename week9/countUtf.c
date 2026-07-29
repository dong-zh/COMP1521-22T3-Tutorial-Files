#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Given a leading UTF8 byte, return how many bytes this utf8 character should take up
unsigned getUtf8CharSize(unsigned char c) {
	printf("processing 0x%x: ", c);

	if ((c & 0b10000000) == 0) {
		printf("1 byte\n");
		return 1;
	}
	if ((c & 0b11100000) == 0b11000000) {
		printf("2 bytes\n");
		return 2;
	}
	if ((c & 0b11110000) == 0b11100000) {
		printf("3 bytes\n");
		return 3;
	}
	if ((c & 0b11111000) == 0b11110000) {
		printf("4 bytes\n");
		return 4;
	}
	errx(EXIT_FAILURE, "invalid utf8 byte!?!?!? 0x%x", c);
}

int main(int argc, char *argv[]) {
	// Arg check
	if (argc != 2)
		errx(EXIT_FAILURE, "Usage: %s <UTF8 string>", argv[0]);


	unsigned nChars = 0;
	char *ptr = argv[1];

	while (*ptr != '\0') {
		nChars++;
		unsigned charSize = getUtf8CharSize(*ptr);
		ptr += charSize;
	}

	// "hello world"
	//             ^

	printf("The string %s has %u characters\n", argv[1], nChars);
}
