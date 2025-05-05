# Minishell

*Oh daring architect of the digital cosmos, prepare thyself to embark upon an odyssey of unparalleled grandeur. As the ancient mariners once charted the seas of the unknown, so too shall you traverse the realm of the command line, forging a shell—a beacon for those who seek dominion over the machine!*

---

## Prelude: The Genesis of the Shell

*In the primordial era of computing, when the vast wilderness of binary stretched endlessly, humanity sought a voice—a way to bridge the chasm between man and machine.*

Back then, developers wrestled with the chaotic symphony of ones and zeroes, their communication with the computer akin to deciphering the language of the gods themselves. Frustrated by the tedious toggling of switches, they envisioned a tool, a shell, that could translate their will into commands—a tool capable of bending the machine to their purpose.

Thus, the shell was born. It was not merely a tool but a revolution, a portal through which mere mortals could wield the boundless power of computation. And now, with **Minishell**, you, O valiant coder, shall relive this genesis. You shall become the blacksmith of the digital forge, crafting a shell that echoes the ingenuity of the pioneers and rises to meet the challenges of the modern age.

---

## Table of Contents

- [The Quest](#the-quest)
- [Features](#features)
- [Requirements](#requirements)
- [Getting Started](#getting-started)
- [Command Execution](#command-execution)
- [Error Handling](#error-handling)
- [Testing and Debugging](#testing-and-debugging)
- [Acknowledgments](#acknowledgments)

---

## The Quest

*O adventurer, gird thyself with courage and take up the mantle of creation!*

Your mission is to design and implement **Minishell**, a lightweight yet powerful shell that shall stand as a testament to your mastery of programming. It must be interactive, intuitive, and imbued with the spirit of the classic Unix shells.

But beware! Your path shall be fraught with peril. You shall face the specters of memory leaks, the labyrinths of syntax parsing, and the untamed signals that threaten to derail your journey. Only through wit, determination, and the invocation of **make v** shall you emerge victorious.

---

## Features

*Behold the might of Minishell, a marvel of digital craftsmanship:*

- **Interactive Command Line**: A shell that listens, interprets, and executes with precision.
- **Built-In Commands**: Includes `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.
- **Pipelines**: Seamlessly pipe the output of one command into another (`|`).
- **Redirections**: Redirect input and output with elegance (`<`, `>`, `>>`).
- **Signal Handling**: Gracefully manage interrupts (`Ctrl+C`, `Ctrl+D`, `Ctrl+\\`).
- **Environment Variables**: Dynamically expand and manipulate environment variables.
- **Memory Leaks? Fear Not!**: With the sacred `make v` command, you shall invoke **Valgrind**, the vigilant sentinel against memory corruption.

---

## Requirements

*Arm thyself with these tools to conquer the digital frontier:*

- **Language**: C (crafted with the rigor of the 42 Norm).
- **Compiler**: GCC or Clang.
- **Libraries**: Standard C library and `readline`.
- **Makefile**: Automate your builds with targets:
  - `all`: Build the shell.
  - `clean`: Remove object files.
  - `fclean`: Remove all compiled files and binaries.
  - `re`: Rebuild everything.
  - **`v`**: Rebuild, clear the terminal, and invoke Valgrind for debugging.

---

## Getting Started

*Set sail upon the sea of code and let adventure guide your hand!*

Clone this repository and step into the realm of Minishell:
```bash
git clone https://github.com/nsilva-n/42CC-3-minishell.git
cd 42CC-3-minishell
make
```

To invoke the shell, simply run:
```bash
./minishell
```

Greet the prompt, your gateway to infinite possibilities:
```bash
minishell$
```

For testing and debugging, wield the mighty `make v`:
```bash
make v
```
This command shall summon Valgrind with comprehensive flags, ensuring the purity of your memory and the safety of your program.

---

## Command Execution

*Command the machine, and it shall obey thy will!*  

### Built-In Commands
- `echo`: Print strings to the standard output.
- `cd`: Change the current working directory.
- `pwd`: Display the current working directory.
- `export`: Add or modify environment variables.
- `unset`: Remove environment variables.
- `env`: Display all environment variables.
- `exit`: Bid farewell to the shell.

### External Commands
Minishell supports the execution of external programs, harnessing the power of `execve` to bring your commands to life.

### Pipelines and Redirections
- **Pipes (`|`)**: Chain commands, passing the output of one as the input to the next.
- **Redirections**:
  - Input (`<`): Redirect standard input from a file.
  - Output (`>`): Redirect standard output to a file (overwrite).
  - Append (`>>`): Redirect standard output to a file (append).

---

## Error Handling

🎵 *The path is perilous, but fear not, for every error shall be conquered!* 🎵  

- **Syntax Errors**: Detect and report unmatched quotes, invalid pipes, and other missteps.
- **Memory Management**: Never leave memory unfreed; invoke Valgrind to ensure perfection.
- **Signal Handling**: Respond gracefully to interrupts and EOF signals.
- **File Errors**: Manage permissions and file existence with care.

---

## Testing and Debugging

*Test thy creation against the crucible of commands and the judgment of tools!*

### Debugging with Valgrind
Use `make v` to invoke Valgrind with the following options:
- `--leak-check=full`: Detect and report memory leaks.
- `--show-leak-kinds=all`: Show all types of leaks (definitely lost, indirectly lost, etc.).
- `--track-origins=yes`: Trace the origins of uninitialized values.
- `--track-fds=yes`: Monitor file descriptor usage.

### Example Commands
Test Minishell with a variety of inputs:
```bash
echo "The journey begins!"
cd /tmp
pwd
ls | grep minishell
cat < input.txt > output.txt
```

Compare behavior with `/bin/bash` to ensure fidelity.

---

## Acknowledgments

*With eternal gratitude to the creators of Unix, the 42 curriculum, and the pioneers who forged the first shells, we dedicate this work.*

May your journey through Minishell be remembered as a legend, where every line of code was a stroke of genius and every bug a vanquished foe.
