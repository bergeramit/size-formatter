#pragma once

#include "size_format_export.h"

typedef enum {
	INPUT_TYPE__UNKNOWN = 0,
	INPUT_TYPE__HEX,
	INPUT_TYPE__BYTES,
	INPUT_TYPE__ABBR
} INPUT_TYPE_t;

INPUT_TYPE_t size_format__get_input_type(const char *input);
