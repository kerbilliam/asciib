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
		printf("You are reading this because arguments were passed to btoa.\n");
		return 1;
	}

	int c;
	int character_byte = 0;
	while((c = getchar()) != EOF) {
		if (c == ' ') {
			if (character_byte > 31) putchar(character_byte);
			character_byte = 0;
			continue;
		}
		if (c == '\n' || c == '\r') {
			if (character_byte > 31) putchar(character_byte);
			character_byte = 0;
			putchar(c);
			continue;
		}

		c = c - '0';
		character_byte = (character_byte << 1) + c;
	}
	return 0;
}
