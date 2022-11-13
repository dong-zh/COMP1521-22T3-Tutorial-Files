/**
 * @file createFileInHome.c
 * @author Dongzhu Huang (z5257526)
 * @brief Create a file with the argument as the filename in the home directory.
 * @date 22T1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>


int main(int argc, char *argv[])
{
	// arg check
	if (argc != 2) {
		errx(EXIT_FAILURE, "Usage: %s <file name>", argv[0]);
	}
	char *homeDir = getenv("HOME");
	char *fileName = argv[1];
	// homeDir = "/home/dong"
	// fileName = "hello.txt"
	int strLen = strlen(homeDir) + strlen(fileName) + 2; // +1 for NULL, +1 for /

	char buffer[strLen];
	// Constructs the full path
	snprintf(buffer, strLen, "%s/%s", homeDir, fileName);
	// buffer = "/home/dong/hello.txt"
	printf("Buffer is: %s\n", buffer);

	FILE *file;
	if ((file = fopen(buffer, "w")) == NULL) {
		err(EXIT_FAILURE, "failed to create %s", buffer);
	}

	fclose(file);


	// fopen("/home/dong/hello.txt")
}
