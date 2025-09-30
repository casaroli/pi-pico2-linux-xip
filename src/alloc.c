#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "usage: %s <bytes>\n", argv[0]);
        exit(1);
    }

    int nbytes = atoi(argv[1]);
    printf("allocating %d bytes\n", nbytes);
    void *buffer = malloc((size_t)nbytes);
    printf("got buffer %p\n", buffer);

    if (buffer) {
        free(buffer);
        printf("freeing\n");
    }

    return 0;
}

