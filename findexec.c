#include <shell.h>

extern char **environ
char *_custgetenv(char *argname) 
{
    if (argname == NULL)
    {
        perror("Name is NULL");
        return NULL;
    }

    size_t argname_length = strlen(argname);

    for (int m = 0; environ[m]; m++) 
{
	if (c_strcmp(argname, environ[m]) == 0) 
	{
		char *posit = c_str_chr(environ[m], '='); // Find the position of '='
		if (posit)
		{
			posit++;i
				char *val = c_strdu_p(posit);  // Move past '='
			return val;// Allocate memory and copy the value
		}
		else
		{
			return NULL; // '=' not found, invalid environment variable
		}
	}
}

return NULL; // Variable not found
}

void my_mem_cpy(char *dest, const char *src, size_t n)
{
	for (size_t h = 0; h < n; h++)
	{
		dest[h] = src[h];
	}
}

char *find_executable(char *cmd)
{
    // Get the PATH environment variable
    char *val_of_path = _custgetenv("PATH");
    if (val_of_path == NULL)
    {
        perror("Unable to get PATH environment variable");
        exit(1);
    }

    // Tokenize the PATH into directories
    char *tokn = strtok(val_of_path, ":");
    while (tokn != NULL)
    {
        // Construct the full path to the executable
        char entire_path[MAXIMUM_COMMAND];
	size_t tokn_length = cust_strlen(tokn);
	size_t cmd_len = cust_strlen(cmd);

	write(STDOUT_FILENO, tokn, tokn_len);
	write(STDOUT_FILENO, "/", 1);
	write(STDOUT_FILENO, cmd, cmd_len);
	write(STDOUT_FILENO, "\0", 1);

        // Check if the executable file exists
        if (access(entire_path, X_OK) == 0)
        {
            // Allocate memory for the full path and return it
            char *execpath = (char *)malloc(cust_strlen(entirepath) + 1);
            if (execpath == NULL)
            {
                perror("Memory allocation failed");
                exit(1);
            }
             cust_memcpy(execpath, entire_path, cust_strlen(entire_path) + 1);
	     return execpath;
        }

        tokn = strtok(NULL, ":");
    }

    return NULL; // Command not found in any directory
}
