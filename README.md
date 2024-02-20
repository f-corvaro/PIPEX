<h1 align="center">PIPEX</h1>

<p align="center">
  <a href="https://github.com/f-corvaro/PIPEX">
	<img src="https://github.com/f-corvaro/PIPEX/blob/main/.extra/pipex.png" alt="PIPEX" width="300">
  </a>
</p>

<p align="center">
	<b><i>"Unleash the power of Unix pipelines and redirections with PIPEX - your gateway to system programming."</i></b><br>
</p>
<p align="center" style="text-decoration: none;">
    <a href="https://github.com/f-corvaro/PIPEX/blob/main/.extra/en.subject.pdf"><img alt="subject" src="https://img.shields.io/badge/subject-PIPEX-yellow" /></a>
    <a href="https://github.com/f-corvaro/PIPEX"><img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/f-corvaro/PIPEX?color=blueviolet" /></a>
    <a href="https://github.com/f-corvaro/PIPEX"><img alt="Code language count" src="https://img.shields.io/github/languages/count/f-corvaro/PIPEX?color=yellow" /></a>
    <a href="https://github.com/f-corvaro/PIPEX"><img alt="GitHub top language" src="https://img.shields.io/github/languages/top/f-corvaro/PIPEX?color=blueviolet" /></a>
    <a href="https://github.com/f-corvaro/PIPEX"><img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/f-corvaro/PIPEX?color=yellow" /></a>
</p>

<h3 align="center">Index</h3>

<p align="center">
  <a href="#pipex">PIPEX</a><br>
  <a href="#index">Index</a><br>
  <a href="#about">About</a><br>
  <a href="#folder-structure">Folder Structure</a><br>
  <a href="#about">About</a><br>
  <a href="#mandatory-part">Mandatory part</a><br>
  <a href="#the-rules">The rules</a><br>
  <a href="#bonus-part">Bonus Part</a><br>
  <a href="#understanding-the-pipex-project">Understanding the Pipex Project</a><br>
  <a href="#exit-code">Exit Code</a><br>
  <a href="#file-permissions">File permissions</a><br>
  <a href="#environment">Environment</a><br>
  <a href="#process">Process</a><br>
  <a href="#pids">PIDs</a><br>
  <a href="#redirections">Redirections</a><br>
  <a href="#checking-for-open-processes-and-file-descriptors">Checking for Open Processes and File Descriptors</a><br>
  <a href="#evaluation">Evaluation</a><br>
  <a href="#usefull-tools">Usefull tools</a><br>
  <a href="#correction-sheet">Correction sheet</a><br>
  <a href="#support-me">Support Me</a><br>
  <a href="#skills-developed">Skills developed</a><br>
  <a href="#sources">Sources</a><br>
  <a href="#license">License</a><br>
  <a href="#author">Author</a>
</ul>
</p>
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

## About

<p align="justify">

This project aims to create a program in C that mimics the Unix pipeline mechanism, specifically the `|` (pipe) operator. The pipe operator in Unix/Linux is used to chain multiple commands together, where the output of one command serves as input to the next.

In the context of this project, you'll be expected to create a program that can take two commands as input, execute the first command, capture its output, and then provide that output as input to the second command.

<p>
<br>

**Some rules to keep in mind:**

<p align="justify">

• Your project must be written in C (in accordance with the Norm).

• Your functions should not quit unexpectedly (segmentation fault, bus error, double
free, etc) apart from undefined behaviors.

• All heap allocated memory space must be properly freed when necessary.

• You must submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, use cc, and your Makefile must not relink. And the Makefile must at least contain the rules ```$(NAME), all, clean, fclean and re (bonus if you want maximum score)```.

• If your project allows you to use your libft, you must copy its sources and its
associated Makefile in a libft folder with its associated Makefile. Your project’s
Makefile must compile the library by using its Makefile, then compile the project.

•Global variables are forbidden.

<p>
<br>

### Mandatory part

**Program name:**

<p align="justify">

```pipex``` Which has as arguments 4 elements:

```file1 cmd1 cmd2 file2```

• file1 and file2 -> file names.

• cmd1 and cmd2 -> shell commands with their parameters.

</p>
<br>

**Files to turn in:**

<p align="justify">

```Makefile, *.h, *.c```

</p>
<br>

**External functs. allowed:**

<p align="justify">

Libft authorized, and:

```
1. open, close, read, write,
malloc, free, perror,
strerror, access, dup, dup2,
execve, exit, fork, pipe,
unlink, wait, waitpid

1. ft_printf and any equivalent YOU coded
```

</p>
<br>

***Examples:***

```shell
$> < file1 cmd1 | cmd2 > file2
```

```shell
$> ./pipex infile "ls -l" "wc -l" outfile
```

Should behave like: ```< infile ls -l | wc -l > outfile```

```shell
$> ./pipex infile "grep a1" "wc -w" outfile
```

Should behave like: ```< infile grep a1 | wc -w > outfile```

<p>
<br>

## The rules

<p align="justify">

The program should handle the errors like the shell command.

<br>

## Bonus Part

<p align="justify">

The bonus part requires to handle multiple pipes, as this example:

```shell
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```

Should behave like: ```< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2```


Furthermore, the program needs to support ```«``` and ```»``` when the first parameter is ```"here_doc"```. An example is:

```shell
$> ./pipex here_doc LIMITER cmd cmd1 file
```

Should behave like: ```cmd << LIMITER | cmd1 >> file```
<p>

## Understanding the Pipex Project

<p align="justify">

1. **Understand the Unix Pipe Concept**: Unix pipes are a form of Inter-Process Communication (IPC) that allow data to be shared between two or more processes. In the context of pipex, you'll be using pipes to pass the output of one command (cmd1) as the input to another command (cmd2).

2. **Understand the Required Functions**: You're allowed to use a specific set of functions for this project. Make sure you understand what each function does and how it can be used. Here's a brief overview:

- `open`, `close`, `read`, `write`: These functions are used for file operations.
- `malloc`, `free`: These functions are used for memory allocation and deallocation.
- `perror`, `strerror`: These functions are used for error handling.
- `access`: This function checks the accessibility of a file.
- `dup`, `dup2`: These functions are used to duplicate file descriptors. `dup(int oldfd)` creates a copy of the file descriptor `oldfd`. The new file descriptor returned by the call is the lowest-numbered file descriptor not currently open for the process. `dup2(int oldfd, int newfd)` also duplicates a file descriptor, but it takes an additional argument newfd. If `newfd`is already open, it is first closed. If `oldfd` is a valid file descriptor, then `newfd` is made to refer to the same open file description as `oldfd` and they share file offset and file status flags.
- `execve`: This function is used to execute a file.The execve function is a Unix system call that replaces the current process image with a new process image.  execve takes three arguments: the path to the binary to execute, an array of arguments to pass to the new program, and an array of environment variables for the new program. The new program starts executing at its main function. If execve is successful, it does not return, because the calling process no longer exists. The new process image has completely replaced it. If execve fails (for example, because the specified binary doesn't exist), it returns -1 and sets errno to indicate the error. The original process continues to run in this case.
- `exit`: This function is used to terminate a process.
- `fork`: This function is used to create a new process.
- `pipe`: This function is used to create a pipe between two processes.
- `unlink`: This function is used to delete a file.
- `wait`, `waitpid`: These functions are used to make a process wait for its child processes.

Once you have a good understanding of these concepts and functions, you can start writing the basic structure of your program.

<p>

### Exit Code

<p align="justify">

In Unix-like operating systems, the exit status is represented as an 8-bit unsigned integer. Therefore, the maximum value is 255. However, not all values are available for programmers to use as some are reserved by the system. In the context of the Pipex project, exit codes are used to indicate the status of the program when it finishes executing. By convention:

- a zero exit code indicates success.
- a non-zero exit code indicates an error.

For example, if the program successfully completes its task of mimicking the Unix pipe operator, it should return an exit code of 0. If an error occurs at any point during execution (such as failing to open a file, command not found), the program should return a non-zero exit code. Exit code 127 is used by the shell to indicate that a command could not be found. If you try to execute a command that doesn't exist in the system's PATH, the shell will return an exit status of 127.

<p>

### File permissions

<p align="justify">

In the context of the Pipex project, file permissions are crucial as they determine who can read from or write to the files you're working with.

In Unix-like systems, including both macOS and Linux, file permissions are divided into three categories: user (the owner of the file), group (users in the file's group), and others (everyone else). Each category has separate read, write, and execute permissions.

In the Pipex project, you need to handle file permissions correctly when opening, reading from, and writing to files. For example, if you're trying to read from a file that your program doesn't have read permission for, the `open` call will fail. Similarly, if you're trying to write to a file that your program doesn't have write permission for, the `open` call will also fail. Your program should handle these cases gracefully, just like the shell commands do.

In my pipex program, there are two distinct definitions for file permissions:

The numbers `0644` and `0664` are octal (base-8) representations of the file permissions. In Unix-like systems, file permissions are represented as a three-digit octal number, where each digit represents the permissions for the user, group, and others, respectively.

- `0644` means the user has read and write permissions (6 in octal is 4 (read) + 2 (write)), and the group and others have read permissions (4 in octal).

- `0664` means the user and the group have read and write permissions, and others have read permissions.

The reason for the difference could be due to different default permissions or security policies on macOS and Linux. On some Linux systems, files created by a user are often accessible to other users in the same group, hence the group write permission. On macOS, which is often used as a personal system, the default might be more restrictive.

However, these are just defaults permissions.

<p>

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

### Process

<p align="justify">

The concepts of parent and child processes are very important. When a process creates a new process using the `fork` system call, the original process is called the parent process and the new process is called the child process.

1. **Parent Process**: In Pipex, the parent process is responsible for creating one or more child processes using the `fork` system call. After creating a child process, the parent process may wait for the child to finish execution using the `wait` or `waitpid` system call. In the context of Pipex, the parent process might be responsible for setting up the pipe and redirecting its output to the output file.

2. **Child Process**: The child process is a new process created by the parent. It begins its life as a copy of the parent, but can then replace its program image using the `execve` system call. In Pipex, the child processes are responsible for executing the shell commands. The first child process reads from the input file and writes to the pipe, and the second child process reads from the pipe and writes to the output file.

The use of parent and child processes allows Pipex to mimic the behavior of the pipe operator in the shell. The pipe operator creates a pipeline of processes, with the output of one process being used as the input to the next, and this is exactly what the parent and child processes in Pipex are doing.

<p>

### PIDs

<p align="justify">

PID stands for Process IDentifier. In Unix-like operating systems, every process that is running on the system is assigned a unique PID by the kernel. This PID is used by the system to track and manage the process.

PIDs are integers and they start at 1, with the process with PID 1 being the init process that is started by the kernel at boot time. After that, new processes are assigned PIDs in increasing order, up to a maximum that depends on the system. When the maximum is reached, the system wraps around and starts reusing PIDs from the lower end of the range.

In addition to the PID, each process also has a PPID, or Parent Process IDentifier. This is the PID of the process that started this process. You can use the PPID to find out where a process came from or to track the relationships between processes.

<p>

### Redirections

<p align="justify">

In the context of the Pipex project, "here_doc" refers to a type of redirection in the shell known as a "here document" or "heredoc". This is a way of defining a block of input within a shell script.

A here document is created using the << operator followed by a delimiter. The shell then reads input until it encounters a line containing only the delimiter.

An example is:
```bash
➜  pipex_42 git:(master) ✗ ./pipex here_doc EOF cat sort
 uniq outfile.txt << EOF
heredoc> Mauriziano
heredoc> Mauriziano
heredoc> Genoveffa
heredoc> Igor
heredoc> Uncle
heredoc> Home
heredoc> EOF
here_doc > here_doc > here_doc > here_doc > here_doc > here_doc > here_doc > %
```

```bash
cat outfile.txt
Genoveffa
Home
Igor
Mauriziano
Uncle
```

<p>

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

## Evaluation

### Usefull tools

I've tested my Pipex implementation using various testers, which have been instrumental in identifying edge cases and other significant scenarios. The most effective ones are:

**Be aware that the management of errors and file permissions may vary depending on the system where the tool is executed.**

- [PipexMedic](git@github.com:gmarcha/pipexMedic.git) is a specialized tool for Linux systems. It provides valuable functionality for verifying file permissions, exit code statuses, output files, standard streams, and parallelism.

- [pipex-tester](git@github.com:vfurmane/pipex-tester.git).

- [PipexTester](git@github.com:gsilva-v/PipexTester.git).

- [pipex_tester_42](git@github.com:Yoo0lh/pipex_tester_42.git).

### Correction sheet

<a href="https://github.com/f-corvaro/PIPEX"><img width="650" src="https://github.com/f-corvaro/PIPEX/blob/main/.extra/.cs/pipex1.png">

<a href="https://github.com/f-corvaro/PIPEX"><img width="650" src="https://github.com/f-corvaro/PIPEX/blob/main/.extra/.cs/pipex2.png">

<a href="https://github.com/f-corvaro/PIPEX"><img width="650" src="https://github.com/f-corvaro/PIPEX/blob/main/.extra/.cs/pipex3.png">

<a href="https://github.com/f-corvaro/PIPEX"><img width="650" src="https://github.com/f-corvaro/PIPEX/blob/main/.extra/.cs/pipex4.png">

<a href="https://github.com/f-corvaro/PIPEX"><img width="650" src="https://github.com/f-corvaro/PIPEX/blob/main/.extra/.cs/pipex5.png">

<a href="https://github.com/f-corvaro/PIPEX"><img width="650" src="https://github.com/f-corvaro/PIPEX/blob/main/.extra/.cs/pipex6.png">

</p>
<br>

## Support Me

<p align="justify">
Remember to ⭐ the repository.
If you want to support me:</p>

<p align="center">
<a href="https://ko-fi.com/fcorvaro"><img width="180" img align="center" src="https://github.com/f-corvaro/42.common_core/blob/main/.extra/support-me-ko-fi.svg"><alt=""></a>
<a href="https://github.com/sponsors/f-corvaro"><img width="180" img align="center" src="https://github.com/f-corvaro/42.common_core/blob/main/.extra/support-me-github.svg"><alt=""></a>

<br>

## Skills developed

<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=git,c,vim,vscode" />
  </a>
</p><br>

## Sources

- [Visualization of a fork call in C](https://www.youtube.com/watch?v=QD9YKSg3wCc&list=PLK4FY1IoDcHG-jUt93Cl7n7XLQDZ0q7Tv).

- [Calling fork multiple times](https://www.youtube.com/watch?v=94URLRsjqMQ&list=PLK4FY1IoDcHG-jUt93Cl7n7XLQDZ0q7Tv&index=2).

- [Practical use case for fork and pipe in C](https://www.youtube.com/watch?v=6u_iPGVkfZ4&list=PLK4FY1IoDcHG-jUt93Cl7n7XLQDZ0q7Tv&index=4).

- [Simulating the pipe "|" operator in C](https://www.youtube.com/watch?v=6xbLgZpOBi8&list=PLK4FY1IoDcHG-jUt93Cl7n7XLQDZ0q7Tv&index=5).

- [Communicating between processes (using pipes) in C](https://www.youtube.com/watch?v=Mqb2dVRe0uo&list=PLK4FY1IoDcHG-jUt93Cl7n7XLQDZ0q7Tv&index=6).

- [Introduction to FIFOs (aka named pipes) in C](https://www.youtube.com/watch?v=2hba3etpoJg&list=PLK4FY1IoDcHG-jUt93Cl7n7XLQDZ0q7Tv&index=7).

- [8 Design Patterns EVERY Developer Should Know](https://www.youtube.com/watch?v=tAuRQs_d9F8&list=PLK4FY1IoDcHG-jUt93Cl7n7XLQDZ0q7Tv&index=8).

- [fd, dup()/dup2() system call tutorial](https://www.youtube.com/watch?v=EqndHT606Tw&list=PLK4FY1IoDcHG-jUt93Cl7n7XLQDZ0q7Tv&index=9).

- [pipex tutorial — 42 project](https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901).

- [pipe](https://www.techtarget.com/whatis/definition/pipe#:~:text=In%20Unix%20systems%2C%20a%20pipe,or%20Unix%20shell%20is%20used.).

- [pipex guide](https://reactive.so/post/42-a-comprehensive-guide-to-pipex).

<br>

## License
<p align="center">
<a href="https://choosealicense.com/licenses/mit/"><img src="https://img.shields.io/badge/License-MIT-green.svg" alt="MIT License"></a>
<a href="https://opensource.org/licenses/"><img src="https://img.shields.io/badge/License-GPL%20v3-yellow.svg" alt="GPLv3 License"></a>
<a href="http://www.gnu.org/licenses/agpl-3.0"><img src="https://img.shields.io/badge/license-AGPL-blue.svg" alt="AGPL License"></a>
<br>

## Author

<p align="center"><a href="https://profile.intra.42.fr/users/fcorvaro"><img style="height:auto;" src="https://avatars.githubusercontent.com/u/102758065?v=4" width="100" height="100"alt=""></a>
<p align="center">
<a href="mailto:fcorvaro@student.42roma.it"><kbd>Email</kbd><alt=""></a>
<a href="https://github.com/f-corvaro"><kbd>Github</kbd><alt=""></a>
<a href="https://www.linkedin.com/in/f-corvaro/"><kbd>Linkedin</kbd><alt=""></a>
<a href="https://42born2code.slack.com/team/U050L8XAFLK"><kbd>Slack</kbd><alt=""></a>

<hr/>