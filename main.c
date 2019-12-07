#include <stdio.h>
#include "size_format_export.h"

#define USAGE \
"-- Size Formatter USAGE --\n" \
"\nsf SIZE\n\n" \
"SIZE can be [\"0x9028\", \"109\", \"80kb\", \"0x3aMB\"]\n"


int main(int argc, const char *argv[]) {
	SIZE_FORMAT__return_codes_t return_code;
	size_type_t starting_size;
	if (argc < 2) {
		printf("Wrong number of Params: %d\n", argc);
		goto Error;
	}

	return_code = SIZE_FORMAT_get_size_from_input(argv[1], &starting_size);
	if (return_code != SUCCESS) {
		goto Error;
	}

	SIZE_FORMAT__print_in_all_formats(starting_size);

	goto Success;
Error:
	printf(USAGE);
Success:
	return 0;
}