/** SQD3 EBNF
 *
 * expr -> ['-'] factor { binary_op factor }
 * binary_op -> '+' | '-' | '*' | '/'
 * factor -> 'UINT'
 *
 */

#include <stdlib.h>

#include "lexer.h"

long long expr();
long long factor();
