#include <stdlib.h>
#include "mmio.h"

static size_t hex_to_int(char ch) {
	if (ch >= 'A' && ch <= 'Z') {
		ch += 'a' - 'A';
	}
	if (ch >= '0' && ch <= '9') {
		return ch - '0';
	} else if (ch >= 'a' && ch <= 'f') {
		return 10 + ch - 'a';
	} else {
		return -1;
	}
}

size_t mmio_read_hexadecimal(const char *str) {
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
	if (*str != 'x') {
		return -1;
	}
	str++;
	while (*str != '\0') {
		check = 1;
		temp = hex_to_int(*str);
		if (temp == (size_t)(-1)) {
			return -1;
		}
		if (((size_t)(-1) - temp) / 16 < result) {
			return -1;
			/* overflow */
		}
		result = result * 16 + temp;
		str++;
	}
	if (check) {
		return result;
	} else {
		return -1;
	}
}

