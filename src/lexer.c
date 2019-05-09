#include "lexer.h"

FILE *stream;
token lookeahead;
char lexeme[LEXEME_MAX_SIZE];

/**
 * Funcoes privadas.
 * Essas funcoes serao utilizadas para
 * reconhecer tokens.
 */
bool uint(void) {
  char c = getc(stream);
  int position = 0;

  if (isdigit(c)) {
    lexeme[position++] = c;
    while ((c = getc(stream)) && isdigit(c)) {
      lexeme[position++] = c;
    }
    return true;
  }

  lexeme[position] = '\0';
  ungetc(c, stream);
  return false;
}

void ignore_spaces() {
  char c;
  while ((c = getc(stream)) && isspace(c)) {
  }
  ungetc(c, stream);
}

bool binary_op(void) {
  char c = getc(stream);
  if (c == '+' || c == '-' || c == '*' || c == '/') {
    lexeme[0] = c;
    lexeme[1] = '\0';
    return true;
  }
  ungetc(c, stream);
  return false;
}

token get_next_token(void) {
  ignore_spaces();
  if (uint())
    return UINT;
  if (binary_op())
    return BINARY_OP;
  return 0;
}

void read_lexeme(char *dest) { strcpy(dest, lexeme); }

/**
 * Essas funcoes sao publicas.
 * O parser utilizara essas funcoes.
 */
void match(token expected) {
  if (expected != lookeahead) {
    fprintf(stderr, "expected %d but found %d", expected, lookeahead);
  }
  lookeahead = get_next_token();
}

int get_lookahead(void) { return lookeahead; }

void init_lexer(FILE *input) {
  stream = input;
  strcpy(lexeme, "\0");
  lookeahead = get_next_token();
}
