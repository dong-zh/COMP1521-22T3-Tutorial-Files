#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Hello world!\n");
    printf("Hello was given %d args\n", argc - 1);
    for (int i = 0; i < argc; i++) {
        printf("\tHello arg %d: %s\n", i, argv[i]);
    }
}
