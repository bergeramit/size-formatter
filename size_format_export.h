#pragma once

typedef float size_type_t;
// #define SIZE_PRINT_FORMAT "%f"

typedef enum {
	UNINITIALIZED = 0,
	SUCCESS,
	ERROR_UKNOWN_INPUT_FORMAT,
	ERROR_SIZE_TOO_BIG
} SIZE_FORMAT__return_codes_t;

SIZE_FORMAT__return_codes_t SIZE_FORMAT_get_size_from_input(const char *input, size_type_t *out_size);

#define CONVERTER_FUNCTION(__type, __convert_size) \
	size_type_t SIZE_FORMAT_convert_to_##__type(size_type_t starting_size);

#include "size_format_convert_functions.xm"
#undef CONVERTER_FUNCTION
