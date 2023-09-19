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
        if (take_cmd(prmpt) == 0)
        {
            continue;
        }

        prmpt[cust_strlen(prmpt) - 1] = '\0';

        if (c_strcmp(prmpt, "exit") == 0)
        {
            break;
        }

        exec_prmpt(prmpt);
    }

    return 0;
}

