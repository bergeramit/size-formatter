#ifndef SIZE_FORMATTER_INTERNAL
#define SIZE_FORMATTER_INTERNAL

#include <inttypes.h>
#include "size_format_export.h"

#define MAX_PREFIX_SIZE (2)
#define SIZE_FORMAT__HEX_VALUE (16)
#define SIZE_FORMAT__DECIMAL_VALUE (10)
#define SIZE_FORMAT__BINARY_VALUE (2)

typedef enum {
    HEXADECIMAL,
    BINARY,
    DEFAULT_DECIMAL,
    BASE_TYPES_AMOUNT
} size_format__base_types_t;

typedef struct {
    const size_format__base_types_t type;
    const uint8_t value;
    const char * prefix;
} size_format__base_settings_t;

#define IF_MATCH_BASE_SET_TYPE_AND_BREAK( \
    __input, __base_mark, __actual_prefix_size, __out_base, __base) \
    if (memcmp(__input, __base_mark, __actual_prefix_size) == 0) { \
        __out_base = __base; \
        break; \
    }

#define FOREACH(__object, __object_list) \
    uint8_t i = 0; \
    for (__object = &(__object_list[i]); \
         i < (sizeof(__object_list) / sizeof(__object)); \
         __object = &(__object_list[++i]))

#define DEBUG_LOG(...) \
    printf("DEBUG LOG> "); \
    printf(__VA_ARGS__);

size_format__base_types_t size_format__get_input_base(const char *input);

SIZE_FORMAT__return_codes_t size_format__convert_input_with_base(const char *input,
                                                                 size_format__base_types_t input_base_type,
                                                                 size_type_t *out_size);

#endif /* SIZE_FORMATTER_INTERNAL */