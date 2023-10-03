#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    char *line = NULL;
    size_t len = 0;

    while (1) {
        char prompt[] = "#cisfun$ ";
        write(STDOUT_FILENO, prompt, strlen(prompt));

        if (getline(&line, &len, stdin) == -1) {
            // Handle end of file (Ctrl+D)
            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        // Remove the newline character
        line[strlen(line) - 1] = '\0';

        // Fork a child process
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            // Child process
            char *argv[2];
            argv[0] = line; // Command name
            argv[1] = NULL; // Null-terminate the array

            // Search for the command in the current directory
            execve(line, argv, NULL);
            
            // If execve returns, there was an error
            perror("execve");
            _exit(EXIT_FAILURE); // Use _exit to avoid flushing buffers
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status)) {
                int exit_status = WEXITSTATUS(status);
                char exit_message[64];
                int exit_message_len = snprintf(exit_message, sizeof(exit_message), "Child process exited with status %d\n", exit_status);
                write(STDOUT_FILENO, exit_message, exit_message_len); // Write the message
            }
        }
    }

    free(line);
    return 0;
}

