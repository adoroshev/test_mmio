#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include "mmio.h"

void mmio_iowb(void *mem, uint8_t value) {
	int check = 0;
	int mem_fd = -1;
	mem_fd = open("/dev/port", O_RDWR | O_SYNC);
	if (mem_fd < 0) {
		printf("Cannot access memory at /dev/port\r\n");
		return;
	}
	lseek(mem_fd, (size_t)mem, SEEK_SET);
	check = write(mem_fd, &value, sizeof(uint8_t));
	if (check != sizeof(uint8_t)) {
		printf("Error accessing memory\r\n");
		close(mem_fd);
		return;
	}
	close(mem_fd);
}

