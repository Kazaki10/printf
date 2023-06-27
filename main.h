#ifndef MAIN_H
#define MAIN_H

#define MAX_BUFFER_SIZE 60
#define MAX_BFFR 1024

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

//prototypes/
int _putchar(char c);
void print_char(va_list args, int count);
void print_string(va_list args, intcount);
int _strlen(char s);
int num_lenght(int num);
int int_to_string(int n);
void check_percent(intcount_char);
void handle_char(char c, va_list args, int count);
int _printf(const charformat, ...);
//advance prototypes/
int num_to_b(unsigned int num);
// handler func /
void handle_hex(unsigned int num, char base, charbuffer);
void handle_octal(unsigned int num, char buffer);
void handle_decimal(unsigned int num, charbuffer);
int number_to_hx_to_octal(unsigned int num, char base);
//hex_function//
void print_hex(unsigned int num);
#endif
