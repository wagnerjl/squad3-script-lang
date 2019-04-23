#ifndef __LEXER_H__
#define __LEXER_H__

#include <ctype.h>
#include <stdio.h>

#include "tokens.h"

int get_lookahead();
void match(int expected);

#endif
