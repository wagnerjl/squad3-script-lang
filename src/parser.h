/** SQD3 EBNF
 * 
 * expr -> ['-'] factor { binary_op expr }
 * binary_op -> '+' | '-' | '*' | '/' 
 * factor -> 'UINT' 
 *
 */

#include "lexer.h"

void expr();
