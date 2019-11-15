#include <stdio.h>
#include <stdbool.h>
#include "size_format_export.h"
#include "size_format_internal.h"


#define CONVERTER_FUNCTION(__type, __convert_size) \
	size_type_t SIZE_FORMAT_convert_to_##__type(size_type_t starting_size) { \
		return (starting_size / __convert_size); \
	}

#include "size_format_convert_functions.xm"
#undef CONVERTER_FUNCTION

INPUT_TYPE_t size_format__get_input_type(const char *input) {
	INPUT_TYPE_t input_type = INPUT_TYPE__UNKNOWN;
	/* check the typoe of input */
	return INPUT_TYPE__HEX;
}

SIZE_FORMAT__return_codes_t SIZE_FORMAT_get_size_from_input(const char *input, size_type_t *out_size) {
	SIZE_FORMAT__return_codes_t rc = UNINITIALIZED;
	switch (size_format__get_input_type(input)) {

		case INPUT_TYPE__UNKNOWN:
			rc = ERROR_UKNOWN_INPUT_FORMAT;
			goto Error;
			break;

		case INPUT_TYPE__HEX:
			*out_size = 40;
			break;

		case INPUT_TYPE__BYTES:
			*out_size = 40;
			break;

		case INPUT_TYPE__ABBR:
			*out_size = 40;
			break;
	}
	rc = SUCCESS;
	goto Success;

Error:
	return rc;
Success:
	return SUCCESS;
}
