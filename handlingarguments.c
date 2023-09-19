#include <shell.h>

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

char *cmd[MAXIMUM_COMMAND];
        int cmdval = 0;
        char *tokn = strtok(command_line, " ");

        while (tokn != NULL && cmdval < MAXIMUM_COMMAND - 1)
        {
            cmd[cmdval++] = tokn;
            tokn = strtok(NULL, " ");
        }

        cmd[cmdval] = NULL;
       if (cmdval > 0 && c_strcmp(cmd[0], "exit") == 0) // Null-terminate the argument list    
{
exit(0);
}
pid_t child_processid = fork();
 if (child_processid < 0)
    {
        perror("Fork Failed");
        exit(1);
    }
    else if (child_processid == 0)
    {
        // Tokenize the command_line into command and arguments
        char *path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
        char *tokn = strtok(path, ":");
        while (tokn != NULL)
        {
            char entirepath[MAXIMUM_COMMAND];
            snprintf(entirepath, sizeof(entirepath), "%s/%s", tokn, cmd[0]);

            // Execute the command in the child process
            if (execve(enitrepath, cmd, NULL) >= 0)
            {
                // Print an error message if the executable is not found
                perror("Command not found");
                exit(1);
            }
            token = strtok(NULL, ":");
        }

       char error_message[] = "Command not found: ";
write(STDERR_FILENO, error_message, strlen(error_message));
write(STDERR_FILENO, cmd[0], strlen(cmd[0]));
write(STDERR_FILENO, "\n", 1);
 exit(1);
    }
    else
    {
        int report;
        waitpid(child_processid, &report, 0);
    }
}
