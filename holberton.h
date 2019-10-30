#ifndef FUNCTIONS_PRINTF_H
#define FUNCTIONS_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct types - Struct.
 * @f1: Variable.
 * @f2: Variable.
 */

typedef struct types
{
	char *f1;
	void (*f2)(va_list, char *);
} format_t;

int _printf(const char *format, ...);
int find_type(const char *format, format_t type[], va_list list);
void print_char(va_list list, char *buffer);
void print_string(va_list list, char *buffer);
void print_percent(__attribute__((unused))va_list list, char *buffer);
void print_number(va_list list, char *buffer);
void print_u_number(va_list list, char *buffer);
void reverse(va_list list, char *buffer);
void binary(va_list list, char *buffer);
void octal(va_list list, char *buffer);
void hex(va_list list, char *buffer);
void Hex(va_list list, char *buffer);
void root13(va_list list, char *buffer);
int _putchar(char c);
void rev_string(char *s);
char *_strncat(char *dest, char *src, int n);
int _strlen(char *s);
char *_charncat(char *dest, char src);
void free_buffer(char *buffer);
#endif /* FUNCTIONS_PRINTF_H */
