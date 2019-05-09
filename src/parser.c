#include "parser.h"

unsigned long long expr() {
    unsigned long long expr_result = factor();
    while(get_lookahead() == BINARY_OP) {
        char lexeme[2];
        read_lexeme(lexeme);
        match(BINARY_OP);

        if(lexeme[0] == '+'){
            expr_result += factor();
        } else if(lexeme[0] == '-'){
            expr_result -= factor();
        } else if(lexeme[0] == '*'){
            expr_result *= factor();
        } else if(lexeme[0] == '/'){
            expr_result /= factor();
        }
    }

    return expr_result;
}

unsigned long long factor() {
  char lexeme[LEXEME_MAX_SIZE];
  read_lexeme(lexeme);
  match(UINT);
  return atoll(lexeme);
}
