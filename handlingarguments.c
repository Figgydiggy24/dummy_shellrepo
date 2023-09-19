#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_DISPLAY_LENGTH 100
#define MAXIMUM_COMMAND 100

// Declare the function prototypes before main
int take_cmd(char *prmpt);
void exec_prmpt(char *command_line);

int main()
{
    char prmpt[MAX_DISPLAY_LENGTH];
    while (1)
    {
        write(STDOUT_FILENO, "#cisfun$ ", 9);
        if (take_cmd(prmpt) == 0)
        {
            continue;
        }

        // Remove the trailing newline character
        prmpt[strlen(prmpt) - 1] = '\0';

        if (strcmp(prmpt, "exit") == 0)
        {
            // Exit the shell if the user enters "exit"
            break;
        }

        exec_prmpt(prmpt);
    }

    return 0;
}

int take_cmd(char *prmpt)
{
    ssize_t size_ofchar_read = read(STDIN_FILENO, prmpt, MAX_DISPLAY_LENGTH);
    if (size_ofchar_read < 0)
    {
        perror("Input error");
        exit(1);
    }
    else if (size_ofchar_read == 0)
    {
        // Handle end of file (Ctrl+D)
        write(STDOUT_FILENO, "\n", 1);
        exit(0);
    }
    prmpt[size_ofchar_read] = '\0';
    return size_ofchar_read;
}

void exec_prmpt(char *command_line)
{
    pid_t child_processid = fork();
    if (child_processid < 0)
    {
        perror("Fork Failed");
        exit(1);
    }
    else if (child_processid == 0)
    {
        // Tokenize the command_line into command and arguments
        char *cmd[MAXIMUM_COMMAND];
        int cmdval = 0;
        char *tokn = strtok(command_line, " ");

        while (tokn != NULL && cmdval < MAXIMUM_COMMAND - 1)
        {
            cmd[cmdval++] = tokn;
            tokn = strtok(NULL, " ");
        }

        cmd[cmdval] = NULL; // Null-terminate the argument list

        char *path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
        char *token = strtok(path, ":");
        while (token != NULL)
        {
            char full_path[MAXIMUM_COMMAND];
            snprintf(full_path, sizeof(full_path), "%s/%s", token, cmd[0]);

            // Execute the command in the child process
            if (execve(full_path, cmd, NULL) >= 0)
            {
                // Print an error message if the executable is not found
                perror("Command not found");
                exit(1);
            }
            token = strtok(NULL, ":");
        }

        fprintf(stderr, "Command not found: %s\n", cmd[0]);
        exit(1);
    }
    else
    {
        int report;
        waitpid(child_processid, &report, 0);
    }
}

