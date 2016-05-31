#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>

#include "mpc.h"

#define MAX_INPUT_SIZE 2048

int main() {

    mpc_parser_t* Number   = mpc_new("number");
    mpc_parser_t* Operator = mpc_new("operator");
    mpc_parser_t* Expr     = mpc_new("expr");
    mpc_parser_t* Lithp    = mpc_new("lithp");

    mpca_lang(MPCA_LANG_DEFAULT, "\
            number   : /-?[0-9]+/ ; \
            operator : '+' | '-' | '*' | '/' ; \
            expr     : <number> | '(' <operator> <expr>+ ')' ; \
            lithp    : /^/ <operator> <expr>+ /$/ ; ",
            Number, Operator, Expr, Lithp);

    /* Do it infix instead of prefix (Bonus Marks) */
    /* mpca_lang(MPCA_LANG_DEFAULT, "\ */
    /*         number   : /-?[0-9]+/ ; \ */
    /*         operator : '+' | '-' | '*' | '/' ; \ */
    /*         expr     : <number> | '(' <expr> <operator> <expr> ')' ; \ */
    /*         lithp    : /^/ <expr>+ /$/ ; ", */
    /*         Number, Operator, Expr, Lithp); */

    puts("Lithp Version 0.0.0");
    puts("Press Ctrl-C to exit\n");

    while (1) {
        char* input = readline("lithp> ");
        add_history(input);

        mpc_result_t r;
        if (mpc_parse("<stdin>", input, Lithp, &r)) {
            mpc_ast_print((mpc_ast_t*)r.output);
            mpc_ast_delete((mpc_ast_t*)r.output);
        } else {
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }

        free(input);
    }

    mpc_cleanup(4, Number, Operator, Expr, Lithp);

    return 0;
}
