#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include "mmio.h"

uint32_t mmio_iord(void *mem) {
	uint32_t result = -1;
	int check = 0;
	int mem_fd = -1;
	mem_fd = open("/dev/port", O_RDWR | O_SYNC);
	if (mem_fd < 0) {
		printf("Cannot access memory at /dev/port\r\n");
		return -1;
	}
	lseek(mem_fd, (size_t)mem, SEEK_SET);
	check = read(mem_fd, &result, sizeof(uint32_t));
	if (check != sizeof(uint32_t)) {
		printf("Error accessing memory\r\n");
		close(mem_fd);
		return -1;
	}
	close(mem_fd);
	return result;
}

