#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <err.h>

void *sayWorld(void *data)
{
	while (1) {
		printf("world\n");
		sleep(2);
	}

	return NULL;
}

int main(void)
{
	pthread_t childThread;
	if (pthread_create(&childThread, NULL, sayWorld, NULL) != 0) {
		err(1, "pthread_create failed");
	}

	while (1) {
		printf("hello\n");
		sleep(1);
	}

}
