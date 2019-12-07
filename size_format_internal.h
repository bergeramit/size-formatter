#pragma once

#include "size_format_export.h"

typedef enum {
	INPUT_TYPE__UNKNOWN = 0,
	INPUT_TYPE__HEX, // 0x10
	INPUT_TYPE__DEC, // 10
} INPUT_TYPE_t;

typedef char BASE_t;

INPUT_TYPE_t size_format__get_input_type(const char *input);

SIZE_FORMAT__return_codes_t size_format__convert_input_with_base(const char *input,
                                                                BASE_t input_base,
                                                                size_type_t *out_size);

