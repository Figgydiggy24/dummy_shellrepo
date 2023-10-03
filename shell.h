#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>

#define _originalbuffersize 200
#define g_f 4

ssize_t getline(char **l_ptr, size_t *q, FILE *stream);
size_t _figstrlen(const char *str);
char* fig_con_cat(const char* s_g[], int c_t);

#endif
