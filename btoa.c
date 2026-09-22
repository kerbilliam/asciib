/*
 * btoa: Convert text representing the binary of ascii characters.
 * Each binary sequence (in text) representing a character needs
 * to be delimited by a space ' ' or ended by a newline to be
 * properly printed.
 * Written by William S. Moore
 */
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	if (argc > 1) {
		printf("btoa: Convert text representing the binary of ASCII characters.\n");
		printf("Note 1: Each binary sequence (in text) representing a character needs ");
		printf("to be delimited by a space ' ' or ended by a newline to be properly printed.\n");
		printf("You are reading this because arguments were passed to btoa.\n");
		return 1;
	}

	int c;
	int character_byte = 0;
	while((c = getchar()) != EOF) {
		// print stored byte if delimiter is found
		if (c == ' ' || c == '\n' || c == '\r') {
			if (isprint(character_byte) || isspace(character_byte)) {
				putchar(character_byte);
			}
			character_byte = 0;
			continue;
		}

		// check if c is 1 or 0 then shift into byte
		if (c != '0' && c != '1') {
			fprintf(stderr, "ERROR: Incompatible character!\n");
			return 1;
		}
		c = c - '0'; // convert to digit
		character_byte = (character_byte << 1) + c;
	}
	return 0;
}
