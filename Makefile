SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	gcc $(OBJS) -o test_mmio

%.o: %.c
	gcc -c $< -o $@

clean:
	rm -f $(OBJS) test_mmio
