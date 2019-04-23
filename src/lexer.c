#include "lexer.h"

token lookeahead;

token uint(FILE *stream) {
  char c = getc(stream);
  if (isdigit(c)) {
    while((c = getc(stream)) && isdigit(c)) {
    }
    return 1;
  }
  ungetc(c, stream);
  return 0;
}

int get_next_token(FILE *stream) {
  if(uint(stream)) return UINT;
  return 0;
}

void match(int expected) {
  if (expected != lookeahead) {
    fprintf(stderr, "expected %d but found %d", expected, lookeahead);
  }
  lookeahead = get_next_token(stdin);
}

int get_lookahead() {
    return lookeahead;
}
