// Solution using atomic data types
#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <err.h>
#include <stdatomic.h>
#include <stdlib.h>

// Waits for n nanoseconds
#define SLEEP_NANOSECOND(n) (nanosleep(&(struct timespec){.tv_nsec = n}, NULL))

// Global variable
atomic_int globalTotal = 0;

void *add5k(void *data);

int main(void)
{
	pthread_t thread1, thread2;

	// Create thread 1
	int error = pthread_create(&thread1, NULL, add5k, NULL);
	// Check error
	if (error != 0) {
		errno = error;
		err(EXIT_FAILURE, "Failed to create thread 1");
	}

	// Create thread 2
	error = pthread_create(&thread2, NULL, add5k, NULL);
	// Check error
	if (error != 0) {
		errno = error;
		err(EXIT_FAILURE, "Failed to create thread 2");
	}

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Global variable is %d\n", globalTotal);

	return 0;
}

void *add5k(void *data)
{
	for (int i = 0; i < 5000; i++) {
		globalTotal++;
		// globalTotal += 1 also works
		// globalTotal = globalTotal + 1 does *not* work!

		SLEEP_NANOSECOND(1);
	}

	printf("Thread finished\n");

	return NULL;
}
