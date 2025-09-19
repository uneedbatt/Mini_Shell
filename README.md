# Mini_Shell c


A simple **mini shell** written in C that allows you to execute system commands like a basic terminal.

---

## Features

- Displays a custom prompt (`myshell>`)  
- Reads and interprets user commands  
- Splits commands and their arguments (`argv`)  
- Executes commands by creating a **child process** with `fork()`  
- Uses `execvp()` to run the commands  
- The **parent process waits for the child** using `wait(NULL)`  
- Handles empty commands and allows exiting the shell with `exit`  
- Shows an error message if the command is not found

---

## Installation

1. Make sure `gcc` is installed (Linux, WSL, or MacOS)  
2. Clone or download the project  
3. Compile the program:

```bash
gcc -Wall -Wextra -o minishell minishell.c
