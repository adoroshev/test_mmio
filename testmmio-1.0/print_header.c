#include <stdio.h>
#include "print.h"

void print_header(void) {
	const char *message =
		"#     # #     # ### #######       # ### #######\r\n"
		"##   ## ##   ##  #  #     #      #   #  #     #\r\n"
		"# # # # # # # #  #  #     #     #    #  #     #\r\n"
		"#  #  # #  #  #  #  #     #    #     #  #     #\r\n"
		"#     # #     #  #  #     #   #      #  #     #\r\n"
		"#     # #     #  #  #     #  #       #  #     #\r\n"
		"#     # #     # ### ####### #       ### #######\r\n"
		"\r\n"
		"Type 'help' to get info about available commands\r\n"
		"Type 'quit' or Ctrl+C to quit the program\r\n"
		"Autocomplete is not implemented\r\n"
		"If you kill this process, better reset the terminal!\r\n"
	;
	printf("%s\r\n", message);
}

