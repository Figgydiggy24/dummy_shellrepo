#include <stdio.h>
#include <stdlib.h>

#define _originalbuffersize 200
#define g_f 4

ssize_t getline(char **l_ptr, size_t *q, FILE *stream)
{
	if (*l_ptr == NULL || *q == 0)
	{
		*q = _originalbuffersize;
		*l_ptr = (char *)malloc(*q);
		if (*l_ptr == NULL)
		{
			return -1;
		}
	}
	char *gen = *l_ptr;
	size_t sz = *q;
	size_t b = 0;
	int f;
	
	while ((f = fgetc(stream)) != EOF && f != '\n')
	{
		if (b >= sz - 1)
		{
			sz *= g_f;
			char *tp = (char *)realloc(gen, sz);
			if (tp == NULL)
			{
				return -1;
			}
			gen = tp;
		}
		
		gen[b++] = (char)f;
	}
	
	if (b == 0 && f == EOF)
	{
		return -1;
	}
	
	gen[b] = '\0';
	*l_ptr = gen;
	*q = sz;
	
	return b;
}
