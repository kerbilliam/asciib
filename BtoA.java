import java.io.ByteArrayOutputStream;
import java.io.IOException;

/**
 * btoa: Convert text representing the binary of ASCII characters.
 * Each binary sequence (in text) representing a character needs
 * to be delimited by a space ' ' or ended by a newline to be
 * properly printed.
 * * Ported from C by Gemini.
 */

public class BtoA {
    public static void main(String[] args) {
        // C logic: if (argc > 1)
        if (args.length > 0) {
            System.out.println("btoa: Convert text representing the binary of ASCII characters.");
            System.out.print("Note 1: Each binary sequence (in text) representing a character needs ");
            System.out.println("to be delimited by a space ' ' or ended by a newline to be properly printed.");
            System.out.println("Note 2: The newline character '\\n' is preserved in the output.");
            System.out.println("You are reading this because arguments were passed to btoa.");
            System.exit(1);
        }

        try {
            int c;
            int characterByte = 0;
            // Use a buffer to store bytes until we hit a newline
            ByteArrayOutputStream buffer = new ByteArrayOutputStream();

            // System.in.read() returns -1 at the end of the stream, mimicking EOF
            while ((c = System.in.read()) != -1) {
                
                if (c == ' ') {
                    if (characterByte > 0) {
			    buffer.write(characterByte);
                    }
                    characterByte = 0;
                    continue;
                }

                if (c == '\n' || c == '\r') {
                    if (characterByte > 0) {
			    buffer.write(characterByte);
                    }

                    // Convert the gathered bytes into a UTF-8 String
                    System.out.print(buffer.toString("UTF-8"));
                    System.out.print((char) c);
                    
                    buffer.reset(); // Clear for next line
                    characterByte = 0;
                    continue;
                }

                if (c == '0' || c == '1') {
                    characterByte = (characterByte << 1) + (c - '0');
                }
            }
        } catch (IOException e) {
            System.err.println("Error reading input: " + e.getMessage());
        }
    }
}
