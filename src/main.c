#include <stdio.h>

#include "builtin_functions.h"
#include "debug.h"
#include "parser.h"

int main() {
  init_vtable();

  SQD3_OBJECT *print_ref = build_builtin_function_ref("print", &print_function);
  declare_local_variable("print", print_ref);

  for (;;) {

    print_vtable();

    printf("\n> ");
    char input[120];
    fgets(input, 120, stdin);

    FILE *buffer = fmemopen(input, strlen(input), "r");
    init_lexer(buffer);
    SQD3_OBJECT *result = expr();
    printf("%lld \n", read_integer_from_object(result));
    free_object(result);
  }
  return 0;
}
