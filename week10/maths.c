#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <err.h>
#include <errno.h>

#define MAX 2000000000

// void *f(void *) {}

void *mult(void *arg) {
	// Assume arg is pointing to a double
	double start = *(double *)arg;
	free(arg);
	double answer = 1;

	for (unsigned long i = start; i < MAX; i++) {
		answer *= i;
	}

	double *ptr = malloc(sizeof(double));
	*ptr = answer;
	return ptr;
}

void *add(void *arg) {
	double start = *(double *)arg;
	free(arg);
	double answer = 0;

	for (unsigned long i = start; i < MAX; i++) {
		answer += i;
	}

	double *ptr = malloc(sizeof(double));
	*ptr = answer;
	return ptr;
}


int main(void)
{
	// Make empty thread ID variables
	pthread_t multThreadId = 0;
	pthread_t addThreadId = 0;

	// Malloc the args for the 2 tasks
	double *multArg = malloc(sizeof(double));
	double *addArg = malloc(sizeof(double));
	*multArg = 1;
	*addArg = 0;

	// Spawn the 2 threads
	int error = pthread_create(&multThreadId, NULL, mult, multArg);
	error = pthread_create(&addThreadId, NULL, add, addArg);

	// Make some space for the return value
	double *multResult = 0;
	double *addResult = 0;

	// Main thread waits for the 2 threads to finish
	// (answer will be placed into the result variables)
	error = pthread_join(multThreadId, (void **)&multResult);
	error = pthread_join(addThreadId, (void **)&addResult);

	printf("multAns = %f, addAns = %f\n", *multResult, *addResult);

	free(multResult);
	free(addResult);
}
