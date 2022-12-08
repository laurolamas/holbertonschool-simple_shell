Simple Shell

This program is a simple implementation of a shell that can accept user input, parse the input into separate commands and arguments, and execute the specified command.
It uses the getpatharray function to retrieve the directories specified by the PATH environment variable.
And it uses the check_cmd function to search for the specified command in those directories.

Features

    Accepts user input and parses it into separate commands and arguments
    Retrieves the directories specified by the PATH environment variable using the getpatharray function
    Searches for the specified command in the directories using the check_cmd function
    Creates a child process to execute the specified command
    Handles errors and provides feedback to the user, such as printing an error message when a command is not found

Usage

To use the program, simply compile it using a C compiler, such as gcc, and run the resulting executable file. 
The program will start by printing a prompt, $, and waiting for the user to enter a command. 
The user can enter any valid command, such as ls or pwd, and the program will search for it in the directories specified by the PATH environment variable.
If the command is found, the program will create a child process to execute it. If the command is not found, an error message will be printed.

To exit the program, the user can enter the exit command at the prompt. This will cause the program to terminate and free any allocated memory.

Limitations

This program is a simple implementation of a shell, and it has several limitations.
For example, it does not support command history or command completion, and it does not handle signals or other advanced features
It is intended to provide a basic understanding of how a shell works, and it should not be used as a replacement for a full-featured shell.
