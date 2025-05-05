# Minishell

*Oh valiant sailor of code, set forth your voyage in the realm of Minishell!*

In this project, you shall craft a shell — a noble interpreter of commands — as you delve into the mysteries of process creation, signal handling, and the orchestration of subsystems.

## Prelude

Within this repository lies the essence of **Minishell**, a project designed to test your mettle in the art of system calls and standard library functions. Inspired by the majestic `bash`, your creation shall support the most essential features to navigate and command the Unix seas.

## Table of Contents

- [The Quest](#the-quest)
- [Features](#features)
- [Requirements](#requirements)
- [Getting Started](#getting-started)
- [Commands Supported](#commands-supported)
- [Valgrind and Debugging](#valgrind-and-debugging)
- [Testing](#testing)
- [Acknowledgments](#acknowledgments)

## The Quest

*Embark, O brave coder, on this grand odyssey!*

Your goal is to implement a simple shell, honoring the following requirements:
- Support basic command execution.
- Handle pipes (`|`) and redirections (`>`, `<`).
- Implement built-in commands like `echo`, `cd`, and `exit`.
- Manage environment variables with grace.
- Process signals with the wisdom of a seasoned navigator.

Your shell must reflect the standard behavior of `bash` where possible, but also allow for your unique flair of implementation.

## Features

*Behold the marvels of Minishell:*

- **Process Creation**: Spawn and manage child processes with `fork` and `exec`.
- **Signal Handling**: Gracefully capture and process signals like `CTRL+C` and `CTRL+D`.
- **Pipelines**: Connect commands with pipes to form a flow of data like rivers to the ocean.
- **Redirections**: Redirect input and output streams to files or other commands.
- **Built-in Commands**: Implement core commands (`echo`, `cd`, `pwd`, `env`, `export`, `unset`, `exit`).

## Requirements

*To sail this sea, prepare your ship with these provisions:*

- **Compiler**: GCC or Clang.
- **Libraries**: Standard C library (`<unistd.h>`, `<stdlib.h>`, `<signal.h>`).
- **System Calls**: Familiarize yourself with `fork`, `exec`, `pipe`, and `dup2`.
- **Makefile**: A makefile to build your shell, with targets `all`, `clean`, `fclean`, and `re`.

## Getting Started

*Let us hoist the sails and set course!*

Clone this repository and navigate to the `minishell` directory:
```bash
git clone https://github.com/nsilva-n/42CC-3-minishell.git
cd 42CC-3-minishell
make
```

Launch your shell with:
```bash
./minishell
```

## Commands Supported

*With these spells, command the sea of Unix:*

- `echo`: Print text to standard output.
- `cd`: Change the current working directory.
- `pwd`: Display the current directory.
- `export`: Set environment variables.
- `unset`: Remove environment variables.
- `env`: Show all environment variables.
- `exit`: Exit the shell gracefully.

## Valgrind and Debugging

*To scrutinize your creation, summon the powers of Valgrind:*

Use the `make v` command to run your shell with Valgrind's memory analysis:
```bash
make v
```

This command executes the shell with Valgrind using the custom suppression file `valgrind.supp`. This file is specifically crafted to suppress memory leaks from `readline` and `add_history`, allowing you to focus on other memory management issues.

### About `valgrind.supp`
The `valgrind.supp` file suppresses known leaks related to `readline` and `add_history`. Here’s an example suppression rule:
```text
{
   readline_1
   Memcheck:Leak
   match-leak-kinds: reachable
   ...
   fun:readline
   ...
}
```

### Example Valgrind Command
Alternatively, you can run Valgrind manually:
```bash
valgrind --suppressions=valgrind.supp --leak-check=full --show-leak-kinds=all --track-origins=yes ./minishell
```

### Example Output
```text
==100825== LEAK SUMMARY:
==100825==    definitely lost: 0 bytes in 0 blocks
==100825==    indirectly lost: 0 bytes in 0 blocks
==100825==      possibly lost: 0 bytes in 0 blocks
==100825==    still reachable: 0 bytes in 0 blocks
==100825==         suppressed: 204,195 bytes in 221 blocks
```

For more details, inspect the `valgrind.supp` file [here](https://github.com/nsilva-n/42CC-3-minishell/blob/main/valgrind.supp).

## Testing

*Test thy creation, lest it falter in the storm:*

Run the provided test scripts or create your own scenarios to verify:
- Command execution
- Piping and redirections
- Signal handling
- Built-in commands

Example:
```bash
echo "Testing pipelines..."
echo "ls -l | grep minishell" | ./minishell
```

## Acknowledgments

*With gratitude to the gods of Unix and the authors of bash, we dedicate this work.* 

May your journey through the seas of Minishell bring you enlightenment and mastery over the arcane arts of shell crafting.
