#define GREETING "Hello, suckers!"
#include <stdio.h>

void print_greeting(int n) {
    for (int i = 0; i < n; ++i)
        puts(GREETING);
}

int main() {
    int f, w;

    puts("5 times via for loop");
    for (f = 0; f < 5; ++f)
        print_greeting(1);

    puts("5 times via while loop");
    w = 0;
    while (w < 5) {
        print_greeting(1);
        ++w;
    }

    puts("5 times via function invocation");
    print_greeting(5);

    return 0;
}
