#pragma once

#include "ConfigSettings.h"







//no need
#ifdef TYPE_SYMBOL
struct symbol_1
{
    wchar_t letter[MAX_ALPABET_SYMBOL_LEN+1];
    union {
        char symbol;
        struct {
            char A : 1;
            char B : 1;
            char C : 1;
            char D : 1;
            char E : 1;
            char F : 1;
            char G : 1;
            char H : 1;
        };
    };
};
#endif