#include <stdlib.h>
#include "mmio.h"

size_t mmio_read_octal(const char *str) {
	size_t result = 0;
	size_t temp = 0;
	int check = 0;
	if (str == NULL) {
		return -1;
	}
	if (*str != '0') {
		return -1;
	}
	str++;
	while (*str != '\0') {
		check = 1;
		if (*str < '0' || *str > '7') {
			return -1;
		}
		temp = *str - '0';
		if (((size_t)(-1) - temp) / 8 < result) {
			return -1;
			/* overflow */
		}
		result = result * 8 + temp;
		str++;
	}
	if (check) {
		return result;
	} else {
		return -1;
	}
}

