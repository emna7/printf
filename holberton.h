#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdlib.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

/**
 * struct spec - conversion specifiers and their associated functions
 *
 * @s: conversion specifier
 * @f: function associated with s
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

int ctoa(va_list valist, char *buffer, int *pos, int *n_printed, char *spec);
int stoa(va_list valist, char *buffer, int *pos, int *n_printed, char *spec);
int itoa(va_list valist, char *buffer, int *pos, int *n_printed, char *spec);
int utoa(va_list valist, char *buffer, int *pos, int *n_printed, char *spec);
int pcttoa(va_list valist, char *buffer, int *pos, int *n_printed, char *spec);
int rot13(va_list valist, char *buffer, int *pos, int *n_printed, char *spec);
int storev(va_list valist, char *buffer, int *pos, int *n_printed, char *spec);
int btoa(va_list valist, char *buffer, int *pos, int *n_printed, char *spec);
int otoa(va_list valist, char *buffer, int *pos, int *n_printed, char *spec);
int xtoa(va_list valist, char *buffer, int *pos, int *n_printed, char *spec);
int Xtoa(va_list valist, char *buffer, int *pos, int *n_printed, char *spec);
int Stoa(va_list valist, char *buffer, int *pos, int *n_printed, char *spec);
int ptoa(va_list valist, char *buffer, int *pos, int *n_printed, char *spec);

int ntoa(long n, char *buffer, int *pos, int *n_printed);

void buffer_full(char *buffer, int *pos, int *n_printed);
void string_to_buffer(char *s, char *buffer, int *pos, int *n_printed);

int _strlen(char *s);
char *_strncpy(char *dest, const char *src, int n);
char *_strdup(char *str);
void rev_string(char *s);

#endif
