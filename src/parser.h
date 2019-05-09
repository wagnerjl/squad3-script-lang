/** SQD3 EBNF
 *
 * expr -> ['-'] factor { binary_op factor }
 * binary_op -> '+' | '-' | '*' | '/'
 * factor -> 'UINT'
 *
 */

#include <stdlib.h>

#include "lexer.h"

unsigned long long expr();
unsigned long long factor();
