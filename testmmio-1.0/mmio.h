#ifndef TASK_MMIO_MMIO_H
#define TASK_MMIO_MMIO_H

#include <stddef.h>
#include <stdint.h>

size_t mmio_get_memory_address(const char *str);

size_t mmio_read_decimal(const char *str);

size_t mmio_read_octal(const char *str);

size_t mmio_read_hexadecimal(const char *str);

uint8_t mmio_iorb(void *mem);

uint16_t mmio_iorw(void *mem);

uint32_t mmio_iord(void *mem);

void mmio_iowb(void *mem, uint8_t value);

void mmio_ioww(void *mem, uint16_t value);

void mmio_iowd(void *mem, uint32_t value);

uint8_t mmio_mmrb(void *mem);

uint16_t mmio_mmrw(void *mem);

uint32_t mmio_mmrd(void *mem);

void mmio_mmwb(void *mem, uint8_t value);

void mmio_mmww(void *mem, uint16_t value);

void mmio_mmwd(void *mem, uint32_t value);

#endif

