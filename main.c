#include <stdio.h>
#include "size_format_export.h"

#define USAGE \
"-- Size Formatter USAGE --\n" \
"\nsf SIZE\n\n" \
"SIZE can be [\"0x9028\", \"109\", \"80kb\", \"100kB\"]\n"

#define OUTPUT_FORMATS_TEMPLATE \
"-- Formats --\n" \
"-> \t %.04f\n" \
"-> \t 0x%f\n" \
"-> \t %.04fKb\n" \
"-> \t %.04fKB\n" \
"-> \t %.04fKiB\n" \
"-> \t %.04fMb\n" \
"-> \t %.04fMB\n" \
"-> \t %.04fMiB\n"


int main(int argc, const char *argv[]) {
	SIZE_FORMAT__return_codes_t return_code;
	size_type_t starting_size;
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
		   SIZE_FORMAT_convert_to_Kb(starting_size),
		   SIZE_FORMAT_convert_to_KB(starting_size),
		   SIZE_FORMAT_convert_to_KiB(starting_size),
		   SIZE_FORMAT_convert_to_Mb(starting_size),
		   SIZE_FORMAT_convert_to_MB(starting_size),
		   SIZE_FORMAT_convert_to_MiB(starting_size));

	goto Success;
Error:
	printf(USAGE);
Success:
	return 0;
}