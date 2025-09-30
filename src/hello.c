#include <stdio.h>

static char *something = "something";

void print_something() {
    puts(something);
}

int main(void) {
    puts("hello");
    puts("world");
    printf("something: %p\n", (void *)something);
    printf("&something: %p\n", (void *)&something);
    printf("print_something: %p\n", (void *)print_something);
    print_something();
}

