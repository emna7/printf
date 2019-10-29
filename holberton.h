#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <stdlib.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

/**
* struct spec - function that convert specifiers
* @s: conversion specifier
* @f: is a function
*/
typedef struct spec
{
char s;
int (*f)(va_list, char *, int *, int *, char *);
} spec_t;

int _printf(const char *format, ...);
int (*get_type(char))(va_list, char *, int *, int *, char *);
int print(char *, size_t);

int get_substring_length(const char *s);
int get_specifier_length(const char *s);
int get_printable_length(const char *s);
int contains(char *s, char c);
char validate_spec(char *spec);
void buffer_full(char *buffer, int *pos, int *n_printed);
void string_to_buffer(char *s, char *buffer, int *pos, int *n_printed);
int convert(va_list valist, char *buffer, int *pos, int *n_printed, char *spec);
int _strlen(char *s);
char *_strncpy(char *dest, const char *src, int n);
char *_strdup(char *str);
void rev_string(char *s);


#endif
