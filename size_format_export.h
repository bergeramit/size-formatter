#pragma once

typedef unsigned int foramt_type_t;

typedef enum {
	UNINITIALIZED = 0,
	SUCCESS,
	ERROR_UKNOWN_INPUT_FORMAT,
	ERROR_SIZE_TOO_BIG
} SIZE_FORMAT__return_codes_t;

SIZE_FORMAT__return_codes_t SIZE_FORMAT_get_size_from_input(const char *input, foramt_type_t *out_size);

foramt_type_t SIZE_FORMAT_convert_to_kB(foramt_type_t starting_size);

foramt_type_t SIZE_FORMAT_convert_to_kb(foramt_type_t starting_size);

foramt_type_t SIZE_FORMAT_convert_to_mB(foramt_type_t starting_size);

foramt_type_t SIZE_FORMAT_convert_to_mb(foramt_type_t starting_size);
