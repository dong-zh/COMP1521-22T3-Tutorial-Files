#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILE_PATH "testFile.txt"

int main(void)
{
	FILE *fp;
	int fd;

	fp = fopen(FILE_PATH, "r");

	fp = fopen(FILE_PATH, "w");

	fp = fopen(FILE_PATH, "a+");
}
