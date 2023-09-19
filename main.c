#include <shell.h>
// Function prototypes
int take_cmd(char *prmpt);
void exec_prmpt(char *command);

int main()
{
    char prmpt[MAX_DISPLAY_LENGTH];
    while (1)
    {
	    write(STDOUT_FILENO, "#cisfun$ ", 9);
	   int size_ofchar_read = take_cmd(prmpt);
	  
	   if (take_cmd(prmpt) == 0)
	    {
		    continue;
	    }
	    
	    prmpt[cust_strlen(prmpt) - 1] = '\0';

	    if (c_strcmp(prmpt, "exit") == 0)
	    {
		    break;
	    }
	    char *_execpath = f_exec(prmpt);
	    if (_exec_path != NULL)
	    {
		    exec_prmpt(_execpath);
		    free(_exec_path);
	    }
	    else
	    {
		    char error_message[] = "Command not found: ";
		    write(STDERR_FILENO, error_message, cust_strlen(error_message));
		    write(STDERR_FILENO, prmpt, cust_strlen(prmpt));
		    write(STDERR_FILENO, "\n", 1);
	    }
    }
    return 0;
}

