#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h>

#include "size_format_export.h"
#include "size_format_internal.h"


#define CONVERTER_FUNCTION(__type, __convert_size) \
    void SIZE_FORMAT_print_in_##__type(size_type_t starting_size) { \
        printf(SIZE_FORMATTER__PRINT_FORMAT , starting_size / __convert_size, #__type); \
    }

#include "size_format_convert_functions.xm"
#undef CONVERTER_FUNCTION


SIZE_FORMAT__return_codes_t size_format__convert_input_with_base(const char *input,
                                                                BASE_t input_base,
                                                                size_type_t *out_size) {
    SIZE_FORMAT__return_codes_t rc = UNINITIALIZED;
    char *format = NULL;
    size_type_t input_value = 0;

    input_value = strtol(input, &format, input_base);
    if (*input != '\0' && *format == '\0') {
        *out_size = input_value;
        rc = SUCCESS;
        goto Exit;
    }

    #define CONVERTER_FUNCTION(__type, __convert_size) \
        if (strncmp(format, #__type, 3) == 0) { \
            *out_size = input_value * __convert_size; \
            rc = SUCCESS; \
            goto Exit; \
        }
    #include "size_format_convert_functions.xm"
    #undef CONVERTER_FUNCTION

    rc = ERROR_UKNOWN_INPUT_FORMAT;

Exit:
    return rc;
}

INPUT_TYPE_t size_format__get_input_type(const char *input) {
    return (memcmp(input, "0x", 2) == 0) ? INPUT_TYPE__HEX : INPUT_TYPE__DEC;
}

SIZE_FORMAT__return_codes_t SIZE_FORMAT_get_size_from_input(const char *input, size_type_t *out_size) {
    SIZE_FORMAT__return_codes_t rc = UNINITIALIZED;
    switch (size_format__get_input_type(input)) {

        case INPUT_TYPE__UNKNOWN:
            rc = ERROR_UKNOWN_INPUT_FORMAT;
            goto Exit;
            break;

        case INPUT_TYPE__HEX:
            rc = size_format__convert_input_with_base(input, 16, out_size);
            // should handle errors
            goto Exit;
            break;

        case INPUT_TYPE__DEC:
            rc = size_format__convert_input_with_base(input, 10, out_size);
            // should handle errors
            goto Exit;
            break;
    }
    rc = SUCCESS;

Exit:
    return rc;
}

void SIZE_FORMAT__print_in_all_formats(size_type_t starting_size) {
    printf("-- ALL FORMATS --\n");
    #define CONVERTER_FUNCTION(__type, __convert_size) \
        SIZE_FORMAT_print_in_##__type(starting_size);

    #include "size_format_convert_functions.xm"
    #undef CONVERTER_FUNCTION
}










