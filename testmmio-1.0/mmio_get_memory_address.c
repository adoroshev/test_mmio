#include <stddef.h>
#include "mmio.h"

size_t mmio_get_memory_address(const char *str) {
	size_t result = 0;
	result = mmio_read_decimal(str);
	if (result == -1) {
		result = mmio_read_octal(str);
	}
	if (result == -1) {
		result = mmio_read_hexadecimal(str);
	}
	return result;
}

