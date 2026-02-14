/*
 * btoa: Convert text representing the binary of ascii characters.
 * Each binary sequence (in text) representing a character needs
 * to be delimited by a space ' ' or ended by a newline to be
 * properly printed.
 * Written by William S. Moore
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc > 1) {
		printf("btoa: Convert text representing the binary of ASCII characters.\n");
		printf("Note 1: Each binary sequence (in text) representing a character needs ");
		printf("to be delimited by a space ' ' or ended by a newline to be properly printed.\n");
		printf("Note 2: The newline character '\\n' is presereved in the output.\n");
		printf("You are reading this because arguments were passed to atobin.\n");
		return 1;
	}

	int c;
	int cb = 0;
	while((c = getchar()) != EOF) {
		if ( c == ' ') {
			putchar(cb);
			cb = 0;
			continue;
		}
		if (c == '\n' || c == '\r') {
			if (cb > 31) putchar(cb);
			cb = 0;
			putchar(c);
			continue;
		}

		c = c - '0';
		cb = (cb << 1) + c;
	}
	return 0;
}
