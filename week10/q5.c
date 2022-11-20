#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <err.h>

void *sayHi(void *data)
{
	char *name = (char *)data;
	printf("CHILD: Hey, %s\n", name);

	return "I'm a return value!!!";
}

int main(void)
{
	pthread_t childThread;
	if (pthread_create(&childThread, NULL, sayHi, "Dong") != 0) {
		err(1, "pthread_create failed");
	}


	printf("MAIN: waiting for child...😴\n");

	char *retVal;
	if (pthread_join(childThread, (void **)&retVal) != 0) {
		err(1, "pthread_join failed");
	}

	printf("MAIN: Done!\n");
	// printf("MAIN: Child returned: %s\n", retVal);

}
