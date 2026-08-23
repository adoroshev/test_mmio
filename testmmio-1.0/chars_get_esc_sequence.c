#include <unistd.h>
#include <stddef.h>
#include "chars.h"

enum char_type chars_get_esc_sequence(void) {
	size_t bytes_read = 0;
	char buff[8] = {0};
	bytes_read = read(1, buff, 8);
	if (bytes_read != 2) {
		return CHAR_UNSUPPORTED;
	}
	if (buff[0] == 91) {
		switch(buff[1]) {
		case 65:
			return CHAR_ARROW_UP;
		case 66:
			return CHAR_ARROW_DOWN;
		case 67:
			return CHAR_ARROW_RIGHT;
		case 68:
			return CHAR_ARROW_LEFT;
		default:
			return CHAR_UNSUPPORTED;
		}
	}
	return CHAR_UNSUPPORTED;
}
