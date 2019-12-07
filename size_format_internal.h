#pragma once

#include "size_format_export.h"

typedef enum {
	INPUT_TYPE__UNKNOWN = 0,
	INPUT_TYPE__HEX, // 0x10
	INPUT_TYPE__DEC, // 10
} INPUT_TYPE_t;

typedef enum {
	BASE__HEX = 16,
	BASE__DEC = 10
} BASE_t;

#define IF_MATCH_BASE_SET_AND_GOTO(__input, __base_mark, __out_base, __base, __label) \
    if (memcmp(__input, __base_mark, 2) == 0) { \
        __out_base = __base; \
        goto __label; \
    }

BASE_t size_format__get_input_base(const char *input);

SIZE_FORMAT__return_codes_t size_format__convert_input_with_base(const char *input,
                                                                BASE_t input_base,
                                                                size_type_t *out_size);

