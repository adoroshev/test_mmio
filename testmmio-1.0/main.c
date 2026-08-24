#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#include "console.h"


extern void enable_raw_terminal(struct termios *terminal);

static struct termios original_terminal;
static struct termios raw_terminal;
static struct console con;

static void reset_terminal(void);


int main(int argc, char **argv) {
	console_init(&con);
	tcgetattr(0, &original_terminal);
	raw_terminal = original_terminal;
	enable_raw_terminal(&raw_terminal);
	tcsetattr(0, TCSAFLUSH, &raw_terminal);
	atexit(reset_terminal);
	write(1, "\033[47h", 5);
	write(1, "\033[?1049h", 8);
	write(1, "\033[H", 4);
	console_run(&con);
	return 0;
}

static void reset_terminal(void) {
	tcsetattr(0, TCSAFLUSH, &original_terminal);
	console_free(&con);
	write(1, "\033[?1049l", 8);
	write(1, "\033[47l", 5);
}


