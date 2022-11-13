#include <stdio.h>
#include <stdlib.h>
#include <spawn.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <err.h>
#include <errno.h>

extern char **environ;


int main(void)
{
	char *argv[] = {"/usr/bin/date", "+%d-%m-%Y", NULL};
	pid_t childPid;
	if (posix_spawn(&childPid, argv[0], NULL, NULL, argv, environ) != 0) {
		err(EXIT_FAILURE, "failed to spawn %s", argv[0]);
	}


	int childExitCode;
	if (waitpid(childPid, &childExitCode, 0) == -1) {
		err(EXIT_FAILURE, "failed to wait for child %d", childPid);
	}


	printf("main is done, child returned %d\n", childExitCode);


	return 42;
}
