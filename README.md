# ASCII-Binary
Provides two binaries, `atob` and `btoa` that encodes and decodes
text and its binary representation respectively. All input and output
of each program is text from standard in and standard out.
Both support UTF-8 encoded characters.

For example, `atob` outputs the following _text_ when given "hello!" from 
standard input:
```
01101000 01100101 01101100 01101100 01101111 00100001
```

## Building
```sh
make
```
This creates the `atob` and `btoa` binaries.

### Java Version
If for some unlikely reason you want to use the Java version of the program,
run the command below to make the two `.class` files.
```sh
make java
```
> The java version was made by AI when prompted to translate atob and btoa
to Java for fun.

## Installing
You need to be on a UNIX-like system with the `$HOME` environment variable set.
It is to be assumed that `$HOME/.local/bin` is part of the `$PATH` environment
variable to consider it to being "installed". Otherwise, simply build the
binaries (or java .class files) and manually install them.

```sh
make all local-install
```

This creates the `atob` and `btoa` binaries and moves them to `$HOME/.local/bin`.

# Usage
## atob (ascii to binary)
`atob` converts **input text from standard input** to its UTF-8 encoded binary
representation. Each binary representation for one character is delimited
by a space. Newline characters are preserved in the output of the program.
_`atob` does not accept any arguments._ Therefore, there are multiple ways
to pass text to `atob`:

### Pipes
You can pipe the output of a program to `atob`. For example,
```sh
echo "hello world" | atob
```

### "Read" From File (Input Redirection)
If you have a text file you want to use as input, you can use
`<` or input redirection to pass that text to the program.
```sh
atob < filename
```

### Manual Input
If you want to "interactively" type out each line you want to be converted,
simply run `atob` and type away. Hit enter to convert that line.

## btoa (binary to ascii)
`btoa`, like `atob`, converts text from standard input and thus, uses the
same methods as described above.
It converts text that is the UTF-8 encoded binary
representation of printable characters and
prints the actual characters.

**An important note** for `btoa` is that each 8-bit sequence of binary
that represents a character **needs to be delimited by a space**.

For example, `btoa` outputs `日本語 is supported!`
when given the following input:
```
11100110 10010111 10100101 11100110 10011100 10101100 11101000 10101010 10011110 00100000 01101001 01110011 00100000 01110011 01110101 01110000 01110000 01101111 01110010 01110100 01100101 01100100 00100001
```

