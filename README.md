<h1 align="center"><p align="center">
  <a href="https://github.com/f-corvaro/PIPEX">
	<img src="https://github.com/f-corvaro/PIPEX/blob/main/.extra/pipex.png" alt="PIPEX"></h1>

<p align="center">
	<b><i>"Unleash the power of Unix pipelines and redirections with PIPEX - your gateway to system programming."</i></b><br>
</p>
<p align="center" style="text-decoration: none;">
    <a href="https://github.com/f-corvaro/PIPEX"><img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/f-corvaro/PIPEX?color=blueviolet" /></a>
    <a href="https://github.com/f-corvaro/PIPEX"><img alt="Code language count" src="https://img.shields.io/github/languages/count/f-corvaro/PIPEX?color=yellow" /></a>
    <a href="https://github.com/f-corvaro/PIPEX"><img alt="GitHub top language" src="https://img.shields.io/github/languages/top/f-corvaro/PIPEX?color=blueviolet" /></a>
    <a href="https://github.com/f-corvaro/PIPEX"><img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/f-corvaro/PIPEX?color=yellow" /></a>
</p>

<h3 align="center">Index</h3>
<p align="center">
 <a href="#introduction">Introduction</a><br>
 <a href="#overview">Overview</a><br>
 <a href="#folder-structure">Folder Structure</a><br>
 <a href="#project-requirements---mandatory-part">Project Requirements - Mandatory Part</a><br>
 <a href="#important-rules-and-guidelines">Important Rules and Guidelines</a><br>
 <a href="#program-name">Program name</a><br>
 <a href="#files-to-submit">Files to Submit</a><br>
 <a href="#allowed-external-functions">Allowed External Functions</a><br>
 <a href="#error-handling-guidelines">Error Handling Guidelines</a><br>
 <a href="#pipex-usage-examples">Pipex Usage Examples</a><br>
 <a href="#project-requirements---bonus-part">Project Requirements - Bonus Part</a><br>
 <a href="#theoretical-background">Theoretical Background</a><br>
 <a href="#unix-pipe">Unix Pipe</a><br>
 <a href="#understand-the-required-functions">Understand the Required Functions</a><br>
 <a href="#file-descriptors-and-redirections">File descriptors and redirections</a><br>
 <a href="#file-permissions">File permissions</a><br>
 <a href="#process-management-in-pipex">Process Management in Pipex</a><br>
 <a href="#pids">PIDs</a><br>
 <a href="#exit-code">Exit Code</a><br>
 <a href="#checking-for-open-processes-and-file-descriptors">Checking for Open Processes and File Descriptors</a><br>
 <a href="#environment">Environment</a><br>
 <a href="#environment-variables">Environment Variables</a><br>
 <a href="#usefull-testing-tools">Useful Testing Tools</a><br>
 <a href="#developed-skills">Developed Skills</a><br>
 <a href="#references">References</a><br>
 <a href="#support-and-contributions">Support and Contributions</a><br>
 <a href="#author">Author</a><br>
</p>
<br>

## Introduction

<p align="justify">

The Pipex project is a part of the 42 curriculum and aims to create a program in C that mimics the Unix pipeline mechanism. This mechanism is based on the `|` (pipe) operator, which allows chaining multiple commands together, with the output of one command serving as input to the next.

In this project, the goal is to develop a program that takes two commands as input, executes the first command, captures its output, and then provides that output as input to the second command. This requires a deep understanding of concepts such as file operations, memory allocation, error handling, process management, and inter-process communication.

<p>
<br>

### Overview

<p align="justify">

The Pipex project involves creating a program that emulates the behavior of the Unix pipeline mechanism. The program takes two commands as arguments and executes them in a way that mimics the behavior of the `|` operator.

To achieve this, the program needs to handle various technical aspects, including:

- File operations: The program needs to open, read, and write files as part of the pipeline process.
- Memory allocation: Proper memory allocation and deallocation are crucial for efficient program execution and avoiding memory leaks.
- Error handling: The program should handle errors gracefully and provide meaningful error messages to the user.
- Process management: The program needs to manage multiple processes and ensure proper synchronization and communication between them.
- Inter-process communication: The program should establish communication channels between processes to pass data from one command to another.
- Input and output redirection: The program should support input and output redirection using the `<<` and `>>` operators.

By understanding and implementing these technical aspects, students gain valuable knowledge and skills in system programming, Unix/Linux environments, and the C programming language.

<p>
<br>

## Folder Structure

<p align="justify">

```
.
├── pipex
│   ├── include
│   │   ├── pipex_b.h
│   │   └── pipex.h
│   ├── lib
│   ├── srcs
│   │   ├── ft_environment_op.c
│   │   ├── ft_error_handling.c
│   │   ├── ft_file_in_out_op.c
│   │   ├── ft_init.c
│   │   ├── ft_memory_management.c
│   │   ├── ft_no_environment_op.c
│   │   ├── ft_pipe.c
│   │   ├── ft_process_management.c
│   │   ├── ft_utils.c
│   │   └── main.c
│   ├── srcs_b
│   │   ├── ft_environment_op_b.c
│   │   ├── ft_error_handling_b.c
│   │   ├── ft_file_in_out_op_b.c
│   │   ├── ft_init_b.c
│   │   ├── ft_memory_management_b.c
│   │   ├── ft_no_environment_op_b.c
│   │   ├── ft_pipe_b.c
│   │   ├── ft_process_management_b.c
│   │   ├── ft_utils_b.c
│   │   └── main_b.c
│   └── Makefile
└── README.md
```

<br>

## Project Requirements - Mandatory Part

### Important Rules and Guidelines

<p align="justify">

- The project must be written in C, following the Norm guidelines.
- Functions should not terminate unexpectedly with errors such as segmentation faults or bus errors, except for undefined behaviors.
- All dynamically allocated memory must be properly freed when no longer needed.
- Include a Makefile that compiles the source files with the flags -Wall, -Wextra, and -Werror. The Makefile should use the cc compiler and should not relink. It should include the rules $(NAME), all, clean, fclean, and re (bonus for maximum score).
- If the project allows the use of a libft library, copy its sources and associated Makefile into a libft folder. The project's Makefile should compile the library using its Makefile and then compile the project.
- Global variables are forbidden.

<p>

### Program name

<p align="justify">

`pipex` is a program that takes 4 arguments:

```file1 cmd1 cmd2 file2```

- `file1` and `file2` are the names of input and output files respectively.
- `cmd1` and `cmd2` are shell commands along with their parameters.

The purpose of `pipex` is to execute `cmd1`, capture its output, and then provide that output as input to `cmd2`. This mimics the behavior of the Unix pipeline mechanism, where multiple commands are chained together using the `|` operator.

By using `pipex`, you can easily process data from one command to another, enabling powerful data manipulation and system programming capabilities.

To use `pipex`, simply provide the appropriate file names and shell commands as arguments, and the program will handle the rest.

</p>

### Files to Submit

<p align="justify">

You need to submit the following files: `Makefile`, `*.h`, `*.c`.

</p>

### Allowed External Functions

<p align="justify">

You are permitted to use the `libft` library, along with the following functions:


1. `open, close, read, write, malloc, free, perror, strerror, access, dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid`

2. `ft_printf` and any equivalent functions you have coded

</p>

### Error Handling Guidelines

<p align="justify">

The program should manage errors in a manner similar to how shell commands handle them.

</p>

### Pipex Usage Examples

```bash
$> < file1 cmd1 | cmd2 > file2
```

```bash
$> ./pipex infile "ls -l" "wc -l" outfile
```

This should behave like:

```bash
< infile ls -l | wc -l > outfile
```

```bash
$> ./pipex infile "grep a1" "wc -w" outfile
```

This should behave like: 

```bash
< infile grep a1 | wc -w > outfile
```

<p>
<br>

## Project Requirements - Bonus Part

<p align="justify">

The bonus part of the project introduces additional requirements to handle multiple pipes. For example, the following command:

```bash
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```

should behave like:

```bash
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```

In addition, the program needs to support the use of `«` and `»` when the first parameter is `"here_doc"`. For instance, the command:

```shell
$> ./pipex here_doc LIMITER cmd cmd1 file
```

should behave like:

```shell
cmd << LIMITER | cmd1 >> file
```

These enhancements allow for more flexibility and functionality in the program, enabling the execution of complex command sequences and input/output redirection.

<p>
<br>

## Theoretical Background

### Unix Pipe

<p align="justify">

The Unix pipe is a powerful mechanism for inter-process communication (IPC) that allows data to be shared between two or more processes. It enables the chaining of multiple commands together, with the output of one command serving as the input to the next. The pipe operator, represented by the vertical bar symbol (|), is used to connect the standard output of one command to the standard input of another command. This allows for the seamless flow of data between commands, enabling complex data processing and manipulation.

IPC is a fundamental concept in system programming and is widely used in Unix/Linux environments for tasks such as data filtering, transformation, and aggregation. It provides a flexible and efficient way to build powerful command-line tools and pipelines. By leveraging IPC mechanisms like pipes, shared memory, and message queues, processes can communicate and exchange data with each other.

To complete the Pipex project, you will need to have a solid understanding of various technical aspects, including:

- File operations: You will need to open, read, and write files as part of the pipeline process.
- Memory allocation: Proper memory allocation and deallocation are crucial for efficient program execution and avoiding memory leaks.
- Error handling: Your program should handle errors gracefully and provide meaningful error messages to the user.
- Process management: You will need to manage multiple processes and ensure proper synchronization and communication between them.
- Inter-process communication: Establishing communication channels between processes to pass data from one command to another is essential.
- Input and output redirection: Your program should support input and output redirection using the `<<` and `>>` operators.

<p>
<br>

### Understand the Required Functions 

<p align="justify">

To successfully complete the Pipex project, it is important to have a clear understanding of the required functions. These functions play a crucial role in implementing the pipeline mechanism and ensuring the proper execution of commands. Here is a breakdown of the functions you are allowed to use:

- **pipe**: This function creates a pipe, which serves as a communication channel between two processes. It allows the output of one process to be connected to the input of another process.
- **fork**: The fork function is used to create a new process by duplicating the existing process. This is essential for executing multiple commands in the pipeline.
- **execve**: This function is used to execute a file. It replaces the current process image with a new process image, allowing you to run shell commands and programs.
- **dup** and **dup2**: These functions are used to duplicate file descriptors. `dup` creates a copy of a file descriptor, while `dup2` duplicates a file descriptor to a specific value. These functions are useful for redirecting input and output between commands.
- **wait** and **waitpid**: These functions are used to make a process wait for its child processes to complete. They ensure proper synchronization and prevent the termination of the parent process before the child processes have finished.
- **access**: This function checks the accessibility of a file, allowing you to verify if a file exists and if it can be accessed.
- **exit**: This function is used to terminate a process. It is important to handle program termination properly to ensure the cleanup of resources and avoid any unexpected behavior.
- **unlink**: This function is used to delete a file. It can be useful for removing temporary files created during the pipeline process.
- **open**, **close**, **read**, and **write**: These functions are essential for file operations. They allow you to open, close, read from, and write to files as part of the pipeline process.
- **malloc** and **free**: These functions are used for dynamic memory allocation and deallocation. They are important for efficient memory management and preventing memory leaks.
- **perror** and **strerror**: These functions are used for error handling. `perror` prints a descriptive error message to stderr, while `strerror` returns a string describing the error code.

<p>
<br>

### File descriptors and redirections

<p align="justify">

In the context of the Pipex project, file descriptors and redirections play a crucial role in managing the input and output of commands within the pipeline. File descriptors are integer values that represent open files or input/output streams. By using file descriptors, we can redirect the standard input and output of commands to files or other commands.

To redirect the standard input of a command, we can use the `dup2` function to duplicate the file descriptor of the input file and assign it to the standard input file descriptor (`STDIN_FILENO`). This allows the command to read input from the specified file instead of the keyboard.

Similarly, to redirect the standard output of a command, we can use the `dup2` function to duplicate the file descriptor of the output file and assign it to the standard output file descriptor (`STDOUT_FILENO`). This allows the command to write output to the specified file instead of the terminal.

In the Pipex project, we can use these file descriptor redirection techniques to implement the pipeline mechanism. By creating pipes using the `pipe` function, we can establish communication channels between commands. We can then redirect the standard output of one command to the write end of the pipe, and the standard input of the next command to the read end of the pipe. This allows the output of one command to serve as the input to the next command, effectively chaining the commands together.

In the context of the Pipex project, "here_doc" refers to a type of redirection in the shell known as a "here document" or "heredoc". This is a way of defining a block of input within a shell script.

A here document is created using the << operator followed by a delimiter. The shell then reads input until it encounters a line containing only the delimiter.

An example of using a here document in the Pipex project would be:

```bash
./pipex here_doc EOF cat sort
 uniq outfile.txt << EOF
Mauriziano
Mauriziano
Genoveffa
Igor
Uncle
Home
EOF
```

This would redirect the contents of the here document to the `cat` command, which would then be piped to the `sort` command. The output would be written to the `outfile.txt` file.

<p>
<br>

### File permissions

<p align="justify">

In the context of the Pipex project, understanding and managing file permissions is crucial. File permissions determine who can read from or write to the files you're working with.

In Unix-like systems, such as macOS and Linux, file permissions are divided into three categories: user (the owner of the file), group (users in the file's group), and others (everyone else). Each category has separate read, write, and execute permissions.

When working with files in the Pipex project, it is important to handle file permissions correctly. For example, if your program does not have read permission for a file you are trying to read from, the `open` call will fail. Similarly, if your program does not have write permission for a file you are trying to write to, the `open` call will also fail. It is essential to handle these cases gracefully, just like shell commands do.

In the Pipex program, two distinct definitions for file permissions are used: `0644` and `0664`. These numbers are octal (base-8) representations of the file permissions. In Unix-like systems, file permissions are represented as a three-digit octal number, where each digit represents the permissions for the user, group, and others, respectively.

- `0644` means the user has read and write permissions (6 in octal is 4 (read) + 2 (write)), and the group and others have read permissions (4 in octal).

- `0664` means the user and the group have read and write permissions, and others have read permissions.

The reason for the difference in default permissions between macOS and Linux could be due to different default settings or security policies. On some Linux systems, files created by a user are often accessible to other users in the same group, hence the group write permission. On macOS, which is often used as a personal system, the default might be more restrictive.

However, it is important to note that these are just default permissions and can be modified as needed.

<p>
<br>

### Process Management in Pipex

<p align="justify">

In the context of the Pipex project, understanding the concept of processes is crucial. When a program is executed, it creates a process that consists of the program's code, data, and resources. In the case of pipex, the main process is referred to as the parent process. When the parent process encounters a fork function, it creates a new process called the child process. The child process is an exact copy of the parent process, including its code, data, and resources. However, the child process has a different process ID (PID) and is considered a separate entity.

The fork function is a powerful mechanism for process creation in Unix-like operating systems. It allows a process to create a new process by duplicating itself. The child process inherits the memory space, file descriptors, and other resources from the parent process. This allows for parallel execution of multiple commands in the pipex pipeline.

Once the child process is created, both the parent and child processes continue executing from the point of the fork function. However, they can differentiate their behavior based on the return value of the fork function. The parent process receives the PID of the child process as the return value, while the child process receives 0. This allows the parent process to track and manage the child process.

To ensure proper synchronization and prevent the termination of the parent process before the child process has finished, the parent process can use functions like wait and waitpid. These functions allow the parent process to wait for the child process to complete its execution. By managing the child processes, the parent process can control the execution flow of the pipeline and ensure the proper execution of commands.

Proper management of child and parent processes is essential for the successful implementation of the pipex program. It enables the execution of multiple commands in parallel, facilitates inter-process communication, and ensures the correct sequencing of commands in the pipeline.

<p>

#### PIDs

<p align="justify">

PID stands for Process IDentifier. In Unix-like operating systems, every running process is assigned a unique PID by the kernel. The PID is used by the system to track and manage processes.

PIDs are integers that start at 1, with PID 1 assigned to the init process started by the kernel at boot time. Subsequent processes are assigned PIDs in increasing order, up to a maximum determined by the system. When the maximum is reached, the system wraps around and starts reusing PIDs from the lower end of the range.

In addition to the PID, each process has a PPID (Parent Process IDentifier), which represents the PID of the process that started it. The PPID can be used to trace the origin of a process or to establish relationships between processes.

To kill a process, you can use the `kill` command in Unix-like operating systems. The `kill` command sends a signal to a process, requesting it to terminate. The most commonly used signal is SIGTERM (signal number 15), which is a graceful termination signal. You can specify the PID of the process you want to kill as an argument to the `kill` command.

For example, to kill a process with PID 1234, you can run the following command:

```bash
kill 1234
```

If you want to forcefully terminate a process, you can use the SIGKILL signal (signal number 9). However, it is recommended to first try the SIGTERM signal and only resort to SIGKILL if the process does not respond to SIGTERM.

Please note that killing a process abruptly may result in data loss or other unintended consequences. It is important to use caution when terminating processes.

<p>

#### Exit Code

<p align="justify">

In Unix-like operating systems, the exit status is represented as an 8-bit unsigned integer, with a maximum value of 255. However, not all values are available for programmers to use, as some are reserved by the system. In the context of the Pipex project, exit codes are used to indicate the status of the program when it finishes executing. By convention:

- A zero exit code indicates success.
- A non-zero exit code indicates an error.

For example, if the program successfully completes its task of mimicking the Unix pipe operator, it should return an exit code of 0. If an error occurs during execution, such as failing to open a file or a command not found, the program should return a non-zero exit code. The shell uses exit code 127 to indicate that a command could not be found in the system's PATH. If you attempt to execute a command that doesn't exist, the shell will return an exit status of 127.

<p>
<br>

### Checking for Open Processes and File Descriptors

<p align="justify">

In the development of your Pipex program, it's crucial to ensure that all processes and file descriptors are properly managed. This means that any process or file descriptor that is opened should also be closed when it's no longer needed. Failing to do so can lead to resource leaks, which can affect the performance of your program and the system it's running on.

To check if your Pipex program has any open processes or file descriptors that haven't been closed correctly, you can use debugging and profiling tools. One such tool is lsof, which stands for "list open files". This command-line utility can be used to report a list of all open files and the processes that opened them.

To use lsof with your Pipex program, you would run your program in the background and then run lsof with the -p option followed by the PID (process ID) of your program. This will show you a list of all files opened by your program, including both regular files and special files like pipes and sockets.

If you see any files in the lsof output that should have been closed by your program but weren't, this indicates that your program is not managing its file descriptors correctly. Similarly, if you see any child processes that are still running after your program has finished, this indicates that your program is not managing its processes correctly.

Remember, it's important to always close file descriptors and terminate child processes when they're no longer needed. This is not just good practice, it's also a requirement for the Pipex project.

Here's an example of how you can use `lsof` to check for open file descriptors in your Pipex program:

First, you need to run your Pipex program in the background. You can do this by appending an ampersand (`&`) to the end of the command:

```bash
./pipex infile cmd1 cmd2 outfile &
```

When you run a command in the background like this, the shell will print a job number and a process ID (PID). You'll need the PID for the next step.

Let's say the PID was 12345. You can then run `lsof` with the `-p` option followed by the PID:

```bash
lsof -p 12345
```

This will print a list of all files that are currently opened by the process with the PID 12345. This includes not only regular files, but also special files like pipes and sockets.

In the output, look for your `infile` and `outfile`. If your program is managing its file descriptors correctly, these files should not appear in the `lsof` output after your program has finished running. If they do appear, it means that your program has not closed these file descriptors correctly.

Similarly, you can check for child processes that are still running after your program has finished. To do this, you can use the `ps` command with the `-o ppid=` option followed by the PID of your program:

```bash
ps -o ppid= 12345
```

This will print a list of all processes whose parent process is the process with the PID 12345. If your program is managing its processes correctly, there should be no output from this command after your program has finished running. If there is output, it means that your program has not terminated these child processes correctly.

<p>
<br>

### Environment

<p align="justify">

In the Pipex project, understanding the environment and command path is essential for executing shell commands.

1. **Environment**: In Unix-like systems, the environment consists of a set of variables that shape the system's behavior. These variables are passed down to child processes. For instance, the `PATH` variable is a part of the environment and it designates the directories where the system should search for executable files.

2. **Command Path**: When a command is executed in a Unix-like system, the system needs to know the exact location of the executable file for that command. By default, it searches in the directories specified in the `PATH` environment variable. The `PATH` is a list of directories separated by colons. The system scans these directories in order until it locates an executable file with the requested name.

When you use `execve` to execute a command, you must provide the complete path to the command's executable file. This can be found by searching the directories in the `PATH` variable. It's also necessary to pass the environment to `execve`, ensuring that the executed command has access to the same environment as your Pipex program.

If there's no environment, it implies that the `PATH` variable, which is a part of the environment, is unavailable. The `PATH` variable is vital because it directs the system where to search for executable files when a command is executed.

Without an environment, your Pipex program won't be able to locate the executable files for the commands it's supposed to run. This is because the `execve` function, which is used to execute the commands, requires the complete path to the command's executable file. Typically, this path would be found by searching the directories listed in the `PATH` variable.

Without the `PATH` variable, you would need to hardcode the paths to the executable files in your program, or devise another method of locating them. This would make your program less adaptable and more challenging to use, as it would only function if the executable files are in the exact locations specified in your program.

Therefore, managing the scenario where there's no environment is a critical aspect of the Pipex project. Your program should be capable of detecting this situation and either handle it gracefully (for example, by providing a meaningful error message), or find a method to execute the commands without depending on the `PATH` variable.

<p>

#### Environment Variables

<p align="justify">

Another important environment variable is the `HOME` variable, which represents the user's home directory. Many programs use this variable to determine the default location for storing user-specific files and configurations.

The `LANG` variable specifies the language and locale settings for the system. It determines the language used for system messages, the format of dates and numbers, and other localization settings.

Other commonly used environment variables include `USER` (the username of the current user), `SHELL` (the path to the user's default shell), and `PWD` (the current working directory).

You can view the values of environment variables using the `env` command or by accessing them programmatically in your code.

Environment variables provide a flexible way to configure and customize the behavior of programs and processes in Unix-like systems.

<p>
<br>

## Usefull Testing Tools

I've tested my Pipex implementation using various tools, which have been instrumental in identifying edge cases and other significant scenarios. The most effective ones are:

- <a href="https://github.com/gmarcha/pipexMedic">PipexMedic</a>: A specialized tool for Linux systems. It provides valuable functionality for verifying file permissions, exit code statuses, output files, standard streams, and parallelism.
- <a href="https://github.com/vfurmane/pipex-tester">pipex-tester</a>: A comprehensive tester for Pipex.

- <a href="https://github.com/gsilva-v/PipexTester">PipexTester</a>: Another robust tool for testing Pipex implementations.

- <a href="https://github.com/Yoo0lh/pipex_tester_42">pipex_tester_42</a>: A useful tester for Pipex projects.

**Note: The management of errors and file permissions may vary depending on the system where the tool is executed.**

## Developed Skills

<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=git,c,vim,vscode" />
  </a>
</p><br>

## References

- [Visualization of a fork call in C](https://www.youtube.com/watch?v=QD9YKSg3wCc&list=PLK4FY1IoDcHG-jUt93Cl7n7XLQDZ0q7Tv): A video demonstrating how the `fork` system call works in C, with visual aids.
- [Calling fork multiple times](https://www.youtube.com/watch?v=94URLRsjqMQ&list=PLK4FY1IoDcHG-jUt93Cl7n7XLQDZ0q7Tv&index=2): A tutorial on the effects and outcomes of calling `fork` multiple times in a C program.
- [Practical use case for fork and pipe in C](https://www.youtube.com/watch?v=6u_iPGVkfZ4&list=PLK4FY1IoDcHG-jUt93Cl7n7XLQDZ0q7Tv&index=4): An example of using `fork` and `pipe` together in a real-world C application.
- [Simulating the pipe "|" operator in C](https://www.youtube.com/watch?v=6xbLgZpOBi8&list=PLK4FY1IoDcHG-jUt93Cl7n7XLQDZ0q7Tv&index=5): A guide on how to simulate the pipe `|` operator in C using system calls.
- [Communicating between processes (using pipes) in C](https://www.youtube.com/watch?v=Mqb2dVRe0uo&list=PLK4FY1IoDcHG-jUt93Cl7n7XLQDZ0q7Tv&index=6): A tutorial on inter-process communication using pipes in C.
- [Introduction to FIFOs (aka named pipes) in C](https://www.youtube.com/watch?v=2hba3etpoJg&list=PLK4FY1IoDcHG-jUt93Cl7n7XLQDZ0q7Tv&index=7): An introduction to using FIFOs (named pipes) for communication between processes in C.
- [8 Design Patterns EVERY Developer Should Know](https://www.youtube.com/watch?v=tAuRQs_d9F8&list=PLK4FY1IoDcHG-jUt93Cl7n7XLQDZ0q7Tv&index=8): A video covering eight essential design patterns that every developer should be familiar with.
- [fd, dup()/dup2() system call tutorial](https://www.youtube.com/watch?v=EqndHT606Tw&list=PLK4FY1IoDcHG-jUt93Cl7n7XLQDZ0q7Tv&index=9): A tutorial on file descriptors and the `dup`/`dup2` system calls in C.
- [pipex tutorial — 42 project](https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901): A detailed tutorial on implementing the Pipex project, including code examples and explanations.
- [pipe](https://www.techtarget.com/whatis/definition/pipe#:~:text=In%20Unix%20systems%2C%20a%20pipe,or%20Unix%20shell%20is%20used.): An explanation of pipes in Unix systems, their purpose, and usage.
- [pipex guide](https://reactive.so/post/42-a-comprehensive-guide-to-pipex): An in-depth guide covering the theoretical and practical aspects of the Pipex project.

<br>

## Support and Contributions

<p align="center">
If you find this repository helpful, please consider starring it to show your support. Your support is greatly appreciated!</p>

<p align="center">
<a href="https://ko-fi.com/fcorvaro"><img width="180" img align="center" src="https://github.com/f-corvaro/42.common_core/blob/main/.extra/support-me-ko-fi.svg"><alt=""></a>
<a href="https://github.com/sponsors/f-corvaro"><img width="180" img align="center" src="https://github.com/f-corvaro/42.common_core/blob/main/.extra/support-me-github.svg"><alt=""></a>

<br>

## Author

<p align="center"><a href="https://profile.intra.42.fr/users/fcorvaro"><img style="height:auto;" src="https://avatars.githubusercontent.com/u/102758065?v=4" width="100" height="100"alt=""></a>
<p align="center">
<a href="mailto:fcorvaro@student.42roma.it"><kbd>Email</kbd><alt=""></a>
<a href="https://github.com/f-corvaro"><kbd>Github</kbd><alt=""></a>
<a href="https://www.linkedin.com/in/f-corvaro/"><kbd>Linkedin</kbd><alt=""></a>
<a href="https://42born2code.slack.com/team/U050L8XAFLK"><kbd>Slack</kbd><alt=""></a>

<hr/>
