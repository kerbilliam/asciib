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
	char buffer[10]; // 8 bits + possible space + null terminator

	while((c = getchar()) != EOF) {
		if (c == '\n') {
			putchar('\n');
			first_in_line = 1;
		}
		else if (c == '\r') continue;
		else {
			if (!first_in_line) {
				putchar(' ');
			}

			unsigned char mask = 0x80; // start at bit 8 (7)
			for (int i = 0; i < 8; i++) {
				buffer[i] = (c & mask) ? '1' : '0';
				mask >>= 1;
			}
			buffer[8] = '\0';

			fputs(buffer, stdout);

			first_in_line = 0;
		}
	}
	return 0;
}
