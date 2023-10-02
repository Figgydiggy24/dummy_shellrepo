#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to concatenate an array of strings
char* fig_con_cat(const char* s_g[], int c_t)
{
	size_t t_t_l = 0;
	for (int g = 0; g < c_t; g++)
	{
		t_t_l += _figstrlen(s_g[g]);
	}
	char* outcome = (char*)malloc(t_t_l + 1);
	
	if (outcome == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	size_t present_spot = 0;
	for (int g = 0; g < c_t; g++)
	{
		fig_str_cpy(outcome + present_spot, s_g[g]);
		present_spot += _figstrlen(s_g[g]);
	}
	return outcome;
}
