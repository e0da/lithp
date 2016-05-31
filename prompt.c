#define MAX_INPUT_SIZE 2048
#include <stdio.h>

char input[MAX_INPUT_SIZE];

void print_banner() {
    puts("Lithp Version 0.0.0");
    puts("Press Ctrl-C to exit\n");
}

void read_input() {
    fgets(input, MAX_INPUT_SIZE, stdin);
}

void print_prompt() {
    fputs("lithp> ", stdout);
}

void decorate_and_print_input() {
    printf("No, you're a %s", input);
}

int main() {
    print_banner();
    while (1) {
        print_prompt();
        read_input();
        decorate_and_print_input();
    }
    return 0;
}
