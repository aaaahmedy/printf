#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _string_type(char *strg);
int print_int(va_list args, char b[], int flags, int width, int precision,
int size);

#endif
