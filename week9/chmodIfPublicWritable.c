#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <err.h>

void chmodIfPublicWritable(char *filename);

int main(int argc, char *argv[]) {
	// arg check
	if (argc < 2) {
		fprintf(stderr, "Usage %s <file1> [file2]\n", argv[0]);
		return EXIT_FAILURE;
	}

	for (int i = 1; i < argc; i++) {
		chmodIfPublicWritable(argv[i]);
	}
}


void chmodIfPublicWritable(char *filename) {
	// rwx rwx rwx
	//          ^

	// Check if file is public writable
	// If it is, make it not public writable
	// Otherwise do nothing
	struct stat fileInfo;
	int error = stat(filename, &fileInfo);
	if (error)
		// err prints the erro (by inspecting errno) and then exits the program with code EXIT_FAILURE (1)
		err(EXIT_FAILURE, "failed to stat %s", filename);

	mode_t perms = fileInfo.st_mode;
	if ((perms & S_IWOTH) == 0) {
		// not public writable, nothing to do
		printf("nothing to do for %s, already not public writable\n", filename);
	} else {
		// we need to chmod and unset the public write bit
		// x and 0 = 0
		// x and 1 = x
		// perms = 0b 111 100 110
		// mask =  0b 111 111 101
		// -------------------AND
		//         0b 111 100 100
		mode_t newPerms = perms & ~S_IWOTH;

		error = chmod(filename, newPerms);
		if (error)
			err(EXIT_FAILURE, "failed to chmod %s", filename);
		printf("Removed public write for %s\n", filename);
	}
}
