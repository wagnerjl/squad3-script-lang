/** SQD3 EBNF
 *
 * expr -> ['-'] factor { binary_op expr }
 * binary_op -> '+' | '-' | '*' | '/'
 * factor -> 'UINT'
 *
 */

#include <stdlib.h>

#include "lexer.h"

void expr();
unsigned long long factor();
