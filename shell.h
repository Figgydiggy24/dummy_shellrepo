#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_DISPLAY_LENGTH 100
#define MAXIMUM_COMMAND 100

int take_cmd(char *prmpt);
void parse_prmpt(char *prmpt, char **command);
void exec_prmpt(char **command);
char *myown_strcat(char *dest, const char *src);
char *ptr = destination;

//for string related functions//
size_t cust_strlen(const char *inpstr);
int cust_strcmp(const char *1st, const char *2st);
char *concat_str(char *destination, const char *source);
