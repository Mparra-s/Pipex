# 🔗 Pipex

## Description

Pipex is a project developed as part of the 42 curriculum.  
The objective is to reproduce the behavior of shell pipes by creating a program that connects the output of one command to the input of another.

This project introduces the use of Unix system calls related to process creation, inter-process communication, and file descriptor manipulation.
This project focuses on correctness and a clear understanding of Unix process handling rather than optimization.
Special attention is given to file descriptors and error management.

<br/>

## Project Objectives

- Understand and use Unix pipes
- Manage processes using `fork`
- Execute commands with `execve`
- Handle file descriptors and redirections
- Reproduce shell-like behavior for command pipelines
- Respect the constraints and norms defined by 42

<br/>

## Program Usage

The program is executed as follows:

```bash
./pipex infile cmd1 cmd2 outfile
```

This is equivalent to the following shell command:
```bash
Copy code
< infile cmd1 | cmd2 > outfile
```
<br/>

## Behavior
- The program reads from infile
- The output of cmd1 is piped to the input of cmd2
- The final output is written to outfile
- Files are opened and closed properly
- Errors are handled gracefully

<br/>

## Arguments
- infile — input file
- cmd1 — first command to execute
- cmd2 — second command to execute
- outfile — output file

<br/>

## Files Structure
The project is composed of the following files:
- pipex.c
- pipex_utils.c
- pipex.h

Each file is designed to keep responsibilities clear and separated.

<br/>

## Compilation
To compile the project, use the provided Makefile:

```bash
make
```
This will generate the pipex executable.

Additional rules:
```bash
make clean     # Removes object files
make fclean    # Removes object files and the executable
make re        # Recompiles the project
```
<br/>
