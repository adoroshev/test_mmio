#include <stdlib.h>
#include "mmio.h"

size_t mmio_read_decimal(const char *str) {
	size_t result = 0;
	size_t temp = 0;
	int check = 0;
	if (str == NULL) {
		return -1;
	}
	if (*str == '0' && *(str + 1) == '\0') {
		return 0;
	}
	if (*str < '1' || *str > '9') {
		return -1;
	}
	while (*str != '\0') {
		check = 1;
		if (*str < '0' || *str > '9') {
			return -1;
		}
		temp = *str - '0';
		if (((size_t)(-1) - temp) / 10 < result) {
			return -1;
			/* overflow */
		}
		result = result * 10 + temp;
		str++;
	}
	if (check) {
		return result;
	} else {
		return -1;
	}
}

