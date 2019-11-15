#include <stdio.h>
#include "size_format_export.h"

#define USAGE \
"-- Size Formatter USAGE --\n" \
"\nsf SIZE\n\n" \
"SIZE can be [\"0x9028\", \"109\", \"80kb\", \"100kB\"]\n"

#define OUTPUT_FORMATS_TEMPLATE \
"-- Formats --\n" \
"-> \t %d\n" \
"-> \t 0x%x\n" \
"-> \t %dkB\n" \
"-> \t %dkb\n" \
"-> \t %dmB\n" \
"-> \t %dmb\n"


int main(int argc, const char *argv[]) {
	SIZE_FORMAT__return_codes_t return_code;
	foramt_type_t starting_size;
	if (argc != 2) {
		printf("Wrong number of Params: %d\n", argc);
		goto Error;
	}

	return_code = SIZE_FORMAT_get_size_from_input(argv[1], &starting_size);
	if (return_code != SUCCESS) {
		goto Error;
	}

	printf(OUTPUT_FORMATS_TEMPLATE,
		   starting_size,
		   starting_size,
		   SIZE_FORMAT_convert_to_kB(starting_size),
		   SIZE_FORMAT_convert_to_kb(starting_size),
		   SIZE_FORMAT_convert_to_mB(starting_size),
		   SIZE_FORMAT_convert_to_mb(starting_size));

	goto Success;
Error:
	printf(USAGE);
Success:
	return 0;
}