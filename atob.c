/*
 * atob: Convert ascii text from standard input to readable binary.
 * Written by William S. Moore
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc > 1) {
		printf("atob: Convert ascii text from standard input to readable binary.\n");
		printf("Note: The newline character '\\n' is presereved in the output.\n");
		printf("You are reading this because arguments were passed to atob.\n");
		return 1;
	}

	int c;
	int first_in_line = 1; // flag to track the start of a line
	int space_offset = 0;
	char buffer[10]; // 8 bits + possible space + null terminator

	while((c = getchar()) != EOF) {
		if (c == '\r') continue; // discard carrige returns

		if (!first_in_line) {
			buffer[0] = ' ';
			space_offset = 1;
		}

		unsigned char mask = 0x80; // start at bit 8 (index 7)
		for (int i = 0 + space_offset; i < 8 + space_offset; i++) {
			buffer[i] = (c & mask) ? '1' : '0';
			mask >>= 1;
		}
		buffer[8 + space_offset] = '\0';
		space_offset = 0;

		fputs(buffer, stdout);

		if (c == '\n') {
			putchar('\n');
			first_in_line = 1;
		} else {
			first_in_line = 0;
		}
	}
	return 0;
}
