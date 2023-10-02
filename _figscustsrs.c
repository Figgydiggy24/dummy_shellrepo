#include <stdio.h>

size_t _figstrlen(const char *str) 
{
	size_t m = 0;
	while (str[m] != '\0')
	{
		m++;
	}
	
	return m;
}


