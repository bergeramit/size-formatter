#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "size_format_export.h"
#include "size_format_internal.h"


#define CONVERTERS(__type, __convert_size) \
    void SIZE_FORMAT_print_in_##__type(size_type_t starting_size) { \
        printf(SIZE_FORMATTER__PRINT_FORMAT , starting_size / __convert_size, #__type); \
    }

#include "size_format_convert_functions.xm"
#undef CONVERTERS

static const char size_format__hex_prefix[MAX_PREFIX_SIZE] = "0x";
static const char size_format__binary_prefix[MAX_PREFIX_SIZE] = "0b";
static const char size_format__decimal_prefix[MAX_PREFIX_SIZE] = {0};

const size_format__base_settings_t size_format__available_bases_table_g[BASE_TYPES_AMOUNT] = {
    {
        HEXADECIMAL,
        SIZE_FORMAT__HEX_VALUE,
        size_format__hex_prefix
    },
    {
        BINARY,
        SIZE_FORMAT__BINARY_VALUE,
        size_format__binary_prefix
    },
    {
        DEFAULT_DECIMAL,
        SIZE_FORMAT__DECIMAL_VALUE,
        size_format__decimal_prefix
    }
};

SIZE_FORMAT__return_codes_t size_format__convert_input_with_base(const char *input,
                                                                 size_format__base_types_t input_base_type,
                                                                 size_type_t *out_input_size) {
    SIZE_FORMAT__return_codes_t rc = UNINITIALIZED;
    char *format = NULL;
    size_type_t input_value = 0;
    uint8_t prefix_length = strnlen(size_format__available_bases_table_g[input_base_type].prefix,
                                    MAX_PREFIX_SIZE);

    input_value = strtol(input + prefix_length,
                         &format,
                         size_format__available_bases_table_g[input_base_type].value);

    if (*input != '\0' && *format == '\0') {
        // no additional specifications such as "Mb"
        *out_input_size = input_value;
        rc = SUCCESS;
        goto Exit;
    }

#ifdef DEBUG
    DEBUG_LOG("Still left suffix\n");
#endif

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
    const size_format__base_settings_t * input_base = NULL;
    size_format__base_types_t out_base_type = DEFAULT_DECIMAL;

    FOREACH(input_base, size_format__available_bases_table_g) {
        IF_MATCH_BASE_SET_TYPE_AND_BREAK(input,
                               input_base->prefix,
                               strnlen(input_base->prefix, MAX_PREFIX_SIZE),
                               out_base_type,
                               input_base->type);
    }

#ifdef DEBUG
    DEBUG_LOG("INPUT TYPE: %d\n", out_base_type);
#endif

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










