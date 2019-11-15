#pragma once

#include "size_format_export.h"

/*
#define MB_SIZE_VALUE  (1000000) // 10 ** 6
#define Mb_SIZE_VALUE  (125000)  // (10 ** 6) / 8
#define MiB_SIZE_VALUE (1048576) // 2 ** 20
#define KB_SIZE_VALUE  (1000)    // 10 ** 3
#define Kb_SIZE_VALUE  (125)     // (10 ** 3) / 8
#define KiB_SIZE_VALUE (1024)    // 2 ** 10
*/

typedef enum {
	INPUT_TYPE__UNKNOWN = 0,
	INPUT_TYPE__HEX,
	INPUT_TYPE__BYTES,
	INPUT_TYPE__ABBR
} INPUT_TYPE_t;

INPUT_TYPE_t size_format__get_input_type(const char *input);

