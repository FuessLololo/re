#include <stdio.h>
#include <stdlib.h>

void unreachableFunction(void) {
    printf("I am hacked! I am a hidden function");
}

int main() {
    puts("Hello, world!\n");
    return 0;
}