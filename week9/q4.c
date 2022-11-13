#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <err.h>

void chmodIfPublicWritable(char *filename);

int main(int argc, char *argv[])
{
	// arg check
	if (argc < 2) {
		fprintf(stderr, "Usage %s <file1> [file2]\n", argv[0]);
		return EXIT_FAILURE;
	}

	// argv = "./a.out" "q4.c" "q7.c" "creatFileInHome.c"
	for (int arg = 1; arg < argc; arg++) {
		chmodIfPublicWritable(argv[arg]);
	}
}


void chmodIfPublicWritable(char *filename)
{
	struct stat fileStat;
	if (stat(filename, &fileStat) == -1) {
		warn("couldn't stat %s", filename);
		return;
	}

	mode_t oldMode = fileStat.st_mode;
	printf("Mode of %s is %o\n", filename, oldMode);

	if (oldMode & S_IWOTH) {
		// file is pub write
		mode_t newMode = oldMode & ~S_IWOTH;
		if (chmod(filename, newMode) == -1) {
			warn("couldn't chmod %s", filename);
		}
	} else {
		// file isn't pub write
		printf("%s is already not public writable\n", filename);
	}
}
