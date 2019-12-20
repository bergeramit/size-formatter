#ifndef SIZE_FORMATTER_EXPORT
#define SIZE_FORMATTER_EXPORT

typedef float size_type_t;
#define SIZE_FORMATTER__PRINT_FORMAT "->   %f %s\n"

typedef enum {
	UNINITIALIZED = 0,
	SUCCESS,
	ERROR_UKNOWN_INPUT_FORMAT,
	ERROR_SIZE_TOO_BIG
} SIZE_FORMAT__return_codes_t;

SIZE_FORMAT__return_codes_t SIZE_FORMAT_get_size_from_input(const char *input, size_type_t *out_size);

void SIZE_FORMAT__print_in_all_formats(size_type_t starting_size);

#define CONVERTERS(__type, __convert_size) \
	void SIZE_FORMAT_print_in_##__type(size_type_t starting_size);

#include "size_format_convert_functions.xm"
#undef CONVERTERS

#endif /* SIZE_FORMATTER_EXPORT */
