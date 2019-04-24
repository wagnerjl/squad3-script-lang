#include "lexer.h"

FILE *stream;
token lookeahead;

/**
 * Funcoes privadas.
 * Essas funcoes serao utilizadas para
 * reconhecer tokens.
 */
token uint() {
  char c = getc(stream);
  if (isdigit(c)) {
    while((c = getc(stream)) && isdigit(c)) {
    }
    return 1;
  }
  ungetc(c, stream);
  return 0;
}

int get_next_token() {
  if(uint(stream)) return UINT;
  return 0;
}

/**
 * Essas funcoes sao publicas.
 * O parser utilizara essas funcoes.
 */
void match(int expected) {
  if (expected != lookeahead) {
    fprintf(stderr, "expected %d but found %d", expected, lookeahead);
  }
  lookeahead = get_next_token(stream);
}

int get_lookahead() {
    return lookeahead;
}

void init_lexer(FILE *input) {
  stream = input;
  lookeahead = get_next_token(stream);
}
