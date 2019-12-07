#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h>

#include "size_format_export.h"
#include "size_format_internal.h"


#define CONVERTERS(__type, __convert_size) \
    void SIZE_FORMAT_print_in_##__type(size_type_t starting_size) { \
        printf(SIZE_FORMATTER__PRINT_FORMAT , starting_size / __convert_size, #__type); \
    }

#include "size_format_convert_functions.xm"
#undef CONVERTERS


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

    #define CONVERTERS(__type, __convert_size) \
        if (strncmp(format, #__type, 3) == 0) { \
            *out_size = input_value * __convert_size; \
            rc = SUCCESS; \
            goto Exit; \
        }
    #include "size_format_convert_functions.xm"
    #undef CONVERTERS

    rc = ERROR_UKNOWN_INPUT_FORMAT;

Exit:
    return rc;
}

BASE_t size_format__get_input_base(const char *input) {
    BASE_t input_base = BASE__DEC;
    IF_MATCH_BASE_SET_AND_GOTO(input,
                               "0x",
                               input_base,
                               BASE__HEX,
                               Exit);

Exit:
    return input_base;
}

SIZE_FORMAT__return_codes_t SIZE_FORMAT_get_size_from_input(const char *input, size_type_t *out_size) {
    SIZE_FORMAT__return_codes_t rc = UNINITIALIZED;
    
    BASE_t input_base = size_format__get_input_base(input);
    rc = size_format__convert_input_with_base(input, input_base, out_size);
    return rc;
}

void SIZE_FORMAT__print_in_all_formats(size_type_t starting_size) {
    printf("-- ALL FORMATS --\n");
    #define CONVERTERS(__type, __convert_size) \
        SIZE_FORMAT_print_in_##__type(starting_size);

    #include "size_format_convert_functions.xm"
    #undef CONVERTERS
}










