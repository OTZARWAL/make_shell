# Make a Shell

A simple Unix shell written in C. This project demonstrates process creation, command execution, argument parsing, quote handling, and basic input/output redirection.

## Features

- Interactive `shell>` prompt
- Executes external commands using `execvp`
- Creates child processes with `fork`
- Waits for commands to finish
- Supports the `exit` command
- Supports input redirection with `<`
- Supports output redirection with `>`
- Removes surrounding single and double quotes
- Handles `SIGQUIT`
- Uses the custom `libft` library
- Compiles with AddressSanitizer enabled

## Build

```bash
make
```

This creates the `main` executable.

Run the shell interactively with:

```bash
./main
```

To automatically run the commands from a file, pass the file path as an
argument:

```bash
./main auto1.txt
```

The shell executes each command in the file. When the file reaches EOF, it
switches back to standard input so you can continue entering commands.

## Usage

Example commands:

```bash
ls
pwd
echo "Hello, shell!"
cat < input.txt
ls > output.txt
exit
```

## Cleanup

Remove object files:

```bash
make clean
```

Remove object files and the executable:

```bash
make fclean
```

Rebuild the project:

```bash
make re
```

## Project Structure

- `main.c` - Main shell loop, command parsing, process creation, and command execution
- `utilities.c` - Quote removal and redirection handling
- `global.h` - Function prototypes and terminal color definitions
- `libft/` - Custom C utility library
- `Makefile` - Build and cleanup commands

## Limitations

This project currently provides basic shell functionality. Advanced features such as pipes, environment-variable expansion, wildcard expansion, command history, and built-in commands such as `cd` are not implemented.
