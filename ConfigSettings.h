#pragma once

#define SEGMENT_NUM 8
#define PINS_IN_PORT_NUM 8
#define strPORT_NAMES "BCD"
#define AVR_PORTS_NUM (sizeof(strPORT_NAMES)-1) //число портов на атмеге

#define PORTLETTERS _T(strPORT_NAMES)
extern const wchar_t port_letter[sizeof(PORTLETTERS)/sizeof(wchar_t)];
#define PORT_NAME L"PORT"

#define EMPTY_IDX 0

#define MAX_ALPABET_SYMBOL_LEN (8-1)