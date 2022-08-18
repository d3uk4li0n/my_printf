#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

#ifndef PRINTF_H
#define PRINTF_H

int my_printf(char *, ...);
int my_strlen(const char *);
void print_char(char);
int absolute(int);
void rev_string(char *, char *);
char* my_strcpy(char *, char *);
char handle_hex(int);
void print_pointer(void *);
char *my_itoa(int, char *, int);

#endif
