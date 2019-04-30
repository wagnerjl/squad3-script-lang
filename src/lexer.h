#ifndef __LEXER_H__
#define __LEXER_H__

#include <ctype.h>
#include <stdio.h>

#include "tokens.h"

// Essa funcao inicializa o lexer
void init_lexer(FILE *input);

// Essas funcoes serao utilizadas no parser
int get_lookahead(void);
void match(int expected);

#endif
