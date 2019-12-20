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

const size_format__base_t SIZE_FORMAT__available_bases_table_g[BASE_TYPES_AMOUNT] = {
    {
        HEXADECIMAL,
        16,
        "0x"
    },
    {
        DEFAULT_DECIMAL,
        10,
        NO_PREFIX
    }
};

SIZE_FORMAT__return_codes_t size_format__convert_input_with_base(const char *input,
                                                                 size_format__base_types_t input_base_type,
                                                                 size_type_t *out_input_size) {
    SIZE_FORMAT__return_codes_t rc = UNINITIALIZED;
    char *format = NULL;
    size_type_t input_value = 0;

    input_value = strtol(input,
                         &format,
                         SIZE_FORMAT__available_bases_table_g[input_base_type].value);

    if (*input != '\0' && *format == '\0') {
        // no additional specifications such as "Mb"
        *out_input_size = input_value;
        rc = SUCCESS;
        goto Exit;
    }

    #define CONVERTERS(__type, __convert_size) \
        if (strncmp(format, #__type, 3) == 0) { \
            *out_input_size = input_value * __convert_size; \
            rc = SUCCESS; \
            goto Exit; \
        }
    #include "size_format_convert_functions.xm"
    #undef CONVERTERS

    rc = ERROR_UKNOWN_INPUT_FORMAT;

Exit:
    return rc;
}

size_format__base_types_t size_format__get_input_base(const char *input) {
    size_format__base_t * input_base = NULL;
    size_format__base_types_t out_base_type = DEFAULT_DECIMAL;

    FOREACH(input_base, SIZE_FORMAT__available_bases_table_g) {
        IF_MATCH_BASE_SET_TYPE(input,
                               input_base->prefix,
                               input_base->actual_prefix_size,
                               out_base_type,
                               input_base->type);
    }
    return out_base_type;
}

SIZE_FORMAT__return_codes_t SIZE_FORMAT_get_size_from_input(const char *input, size_type_t *out_input_size) {
    SIZE_FORMAT__return_codes_t rc = UNINITIALIZED;
    size_format__base_types_t input_base = size_format__get_input_base(input);

    rc = size_format__convert_input_with_base(input, input_base, out_input_size);

Exit:
    return rc;
}

void SIZE_FORMAT__print_in_all_formats(size_type_t starting_size) {
    printf("-- ALL FORMATS --\n");
    #define CONVERTERS(__type, __convert_size) \
        SIZE_FORMAT_print_in_##__type(starting_size);

    #include "size_format_convert_functions.xm"
    #undef CONVERTERS
}










