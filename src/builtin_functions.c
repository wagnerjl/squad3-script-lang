#include "builtin_functions.h"

SQD3_OBJECT *print_function() {
  SQD3_OBJECT *value = recover_from_stack_args(0);
  char result[1024];
  to_string(value, result);
  printf("%s\n", result);
  return value;
}
