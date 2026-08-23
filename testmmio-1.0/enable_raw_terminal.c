#include <stdlib.h>
#include <termios.h>

#include "misc.h"

void enable_raw_terminal(struct termios *terminal) {
	if (terminal == NULL) {
		return;
	}
	tcgetattr(0, terminal);
	terminal->c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	terminal->c_oflag &= ~(OPOST);
	terminal->c_cflag &=  (CS8);
	terminal->c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	terminal->c_cc[VMIN] = 0;
	terminal->c_cc[VTIME] = 1;
}

