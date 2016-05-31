#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>

#define MAX_INPUT_SIZE 2048

int main() {
    puts("Lithp Version 0.0.0");
    puts("Press Ctrl-C to exit\n");

    while (1) {
        char* input = readline("lithp> ");
        add_history(input);
        printf("No, you're a %s\n", input);
        free(input);
    }
    return 0;
}
