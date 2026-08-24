#include <stdio.h>
#include "print.h"

void print_help(void) {
	const char *message =
		"'quit'            - exit the program\r\n"
		"'help'            - get help\r\n"
		"'history'         - print command history\r\n"
		"'clear'           - clear the screen\r\n"
		"'iorb' addr       - read byte from /dev/port\r\n"
		"'iorw' addr       - read word from /dev/port\r\n"
		"'iord' addr       - read dword from /dev/port\r\n"
		"'iowb' addr value - write byte to /dev/port\r\n"
		"'ioww' addr value - write word to /dev/port\r\n"
		"'iowd' addr value - write dword to /dev/port\r\n"
		"'mmrb' addr       - read byte from /dev/mem\r\n"
		"'mmrw' addr       - read word from /dev/mem\r\n"
		"'mmrd' addr       - read dword from /dev/mem\r\n"
		"'mmwb' addr value - write byte to /dev/mem\r\n"
		"'mmww' addr value - write word to /dev/mem\r\n"
		"'mmwd' addr value - write dword to /dev/mem\r\n"
	;
	printf("\r\n%s\r\n", message);
}

