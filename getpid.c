#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t _parPID = getppid();
	printf("parent process ID: %d\n", _parPID);
	return (0);
}
