#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <err.h>

void *sayHi(void *data)
{
	printf("Hello world\n");
	return NULL;
}

int main(void)
{
	pthread_t threadId;
	pthread_create(&threadId, NULL, sayHi, NULL);

	// Main thread will get stuck at this line of code
	// until sayHi finishes
	pthread_join(threadId, NULL);

	printf("MAIN: Done!\n");
}
