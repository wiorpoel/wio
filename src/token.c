#include "../include/token.h"
#include <stdlib.h>


Token * token_init(TokenType type, const char * value, unsigned int line, unsigned int index, unsigned char length) {

    Token * token = (Token *) calloc(1, sizeof(Token));
    token->type = type;
    token->value = value;
    token->line = line;
    token->index = index;
    token->length = length;
    return token;
}