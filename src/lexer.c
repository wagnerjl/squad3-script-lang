#include "lexer.h"

FILE *stream;
token lookeahead;

/**
 * Funcoes privadas.
 * Essas funcoes serao utilizadas para
 * reconhecer tokens.
 */
token uint(void) {
  char c = getc(stream);
  if (isdigit(c)) {
    while((c = getc(stream)) && isdigit(c)) {
    }
    return 1;
  }
  ungetc(c, stream);
  return 0;
}

void ignore_spaces() {
    char c;
    while((c = getc(stream)) && isspace(c));
    ungetc(c, stream);
}

int get_next_token(void) {
  ignore_spaces();
  if(uint()) return UINT;
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
  lookeahead = get_next_token();
}

int get_lookahead(void) {
    return lookeahead;
}

void init_lexer(FILE *input) {
  stream = input;
  lookeahead = get_next_token();
}
