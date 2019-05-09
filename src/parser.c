#include "parser.h"

void expr() {}

unsigned long long factor() {
  char lexeme[LEXEME_MAX_SIZE];
  read_lexeme(lexeme);
  return atoll(lexeme);
}
