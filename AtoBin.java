import java.io.IOException;

public class AtoBin {
    public static void main(String[] args) {
        // Check for command line arguments, similar to argc > 1
        if (args.length > 0) {
            System.out.println("atobin: Convert ascii text from standard input to readable binary.");
            System.out.println("Note: The newline character '\\n' is preserved in the output.");
            System.out.println("You are reading this because arguments were passed to atobin.");
            System.exit(1);
        }

        try {
            int c;
            boolean firstInLine = true;
	    StringBuilder sb = new StringBuilder();

            // System.in.read() returns -1 at the end of the stream (EOF)
            while ((c = System.in.read()) != -1) {
                if (c == '\n') {
                    System.out.println(sb.toString());
		    sb.setLength(0); // clear the buffer for the next line
                    firstInLine = true;
                } else if (c == '\r') {
                    // Handle Windows-style line endings if necessary, 
                    // otherwise ignore to keep output clean.
                    continue; 
                } else {
                    if (!firstInLine) {
                	sb.append(" ");
                    }

                    // Convert the integer to an 8-bit binary string
                    for (int i = 7; i >= 0; --i) {
			    sb.append((c >> i) & 1);
                    }

                    firstInLine = false;
                }
            }
	    if (sb.length() > 0) {
		    System.out.print(sb.toString());
	    }
        } catch (IOException e) {
            System.err.println("Error reading input: " + e.getMessage());
        }
    }
}
