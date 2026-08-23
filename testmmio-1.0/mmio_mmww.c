#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include "mmio.h"

void mmio_mmww(void *mem, uint16_t value) {
	size_t PAGE_SIZE = 256LLU << 20;
	size_t shift = 0;
	void *map_base = NULL;
	int mem_fd = -1;
	mem_fd = open("/dev/mem", O_RDWR | O_SYNC);
	if (mem_fd < 0) {
		printf("Error accessing memory at /dev/mem\r\n");
		return;
	}
	shift = ((size_t)mem) % PAGE_SIZE;
	mem = (void *)((size_t)mem - shift);
	map_base = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE,
		MAP_SHARED, mem_fd, (size_t)mem);
	if (map_base == -1) {
		printf("Invalid address\r\n");
		close(mem_fd);
		return;
	}
	map_base += shift;
	*(uint16_t *)map_base = value;	
	close(mem_fd);
}

