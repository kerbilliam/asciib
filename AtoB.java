import java.io.IOException;

/**
 * atob: Convert ASCII text from standard input to readable binary.
 * Ported from C by Gemini.
 */
public class AtoB {
    public static void main(String[] args) {
        // C logic: if (argc > 1)
        if (args.length > 0) {
            System.out.println("atob: Convert ascii text from standard input to readable binary.");
            System.out.println("Note: The newline character '\\n' is preserved in the output.");
            System.out.println("You are reading this because arguments were passed to atob.");
            System.exit(1);
        }

        try {
            int c;
            boolean firstInLine = true;

            while ((c = System.in.read()) != -1) {
                if (c == '\n') {
                    System.out.print('\n');
                    firstInLine = true;
                } 
                else if (c == '\r') {
                    // Skip carriage returns to match C behavior
                    continue;
                } 
                else {
                    // Add a space between binary blocks, but not at the very start of a line
                    if (!firstInLine) {
                        System.out.print(' ');
                    }

                    // Bit manipulation logic
                    int mask = 0x80; // 10000000 in binary
                    StringBuilder buffer = new StringBuilder();
                    
                    for (int i = 0; i < 8; i++) {
                        buffer.append((c & mask) != 0 ? '1' : '0');
                        mask >>= 1;
                    }
                    
                    System.out.print(buffer.toString());
                    firstInLine = false;
                }
            }
        } catch (IOException e) {
            System.err.println("Error reading input: " + e.getMessage());
        }
    }
}
