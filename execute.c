#include <shell.h>

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
	token = strtok(NULL, ":";
    }
    fprintf(stderr, "Command not found: %s\n", cmd[0]);
            exit(1);
	    {
    else
    }
    {
        int report;
        waitpid(child_processid, &report, 0);
    }
}
