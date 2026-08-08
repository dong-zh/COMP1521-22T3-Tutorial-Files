#include <errno.h>
#include <sched.h>
#include <spawn.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

extern char **environ;

int main(void) {
    // Process ID
    pid_t helloPid = 0;
    char *helloArgv[] = {
        "./hello",
        "one",
        "two",
        "three",
        "bye",
        NULL
    };

    int error = posix_spawn(&helloPid, helloArgv[0], NULL, NULL, helloArgv, environ);

    if (error) {
        errno = error;
        err(EXIT_FAILURE, "failed to posix_spawn %s", helloArgv[0]);
    }
}
