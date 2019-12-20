#ifndef SIZE_FORMATTER_INTERNAL
#define SIZE_FORMATTER_INTERNAL

#include "size_format_export.h"

#define MAX_PREFIX_SIZE (2)
#define NO_PREFIX (0)

typedef enum {
    HEXADECIMAL,
    DEFAULT_DECIMAL,
    BASE_TYPES_AMOUNT
} size_format__base_types_t;

typedef struct {
    size_format__base_types_t type,
    uint8_t value,
    uint8_t actual_prefix_size,
    char prefix[MAX_PREFIX_SIZE],
} size_format__base_t;

#define IF_MATCH_BASE_SET_TYPE( \
    __input, __base_mark, __actual_prefix_size, __out_base, __base) \
    if (memcmp(__input, __base_mark, __actual_prefix_size) == 0) { \
        __out_base = __base; \
    }

#define FOREACH(__object, __object_list) \
    uint8_t i = 0; \
    for (__object = &(__object_list[i]); \
         i < (sizeof(__object_list) / sizeof(__object)); \
         __object = &(__object_list[++i]))

size_format__base_types_t size_format__get_input_base(const char *input);

SIZE_FORMAT__return_codes_t size_format__convert_input_with_base(const char *input,
                                                                 size_format__base_types_t input_base_type,
                                                                 size_type_t *out_size);

#endif /* SIZE_FORMATTER_INTERNAL */