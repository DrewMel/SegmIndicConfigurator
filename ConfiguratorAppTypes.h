#pragma once

#include "ConfigSettings.h"

enum result { OK, ERR };
enum indicator_type { ANODE, CATHODE };

struct segment_pin
{
	unsigned char port : 2;
	unsigned char pin : 4;
};

struct config_info
{
	unsigned char ports_num : 2;
	indicator_type type;
	unsigned char buisy_pins[AVR_PORTS_NUM];
	segment_pin segments[SEGMENT_NUM];
	unsigned char symbols_num;
};

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