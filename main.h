#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int printf_type(const char *fmt, int *i,
va_list argv, char buffer[], int flags, int width, int precision, int size);


int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_str(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percentage(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printf_unsigned_num(va_list argv, char buffer[],
	int flags, int width, int precision, int size);
int printf_oct_num(va_list argv, char buffer[],
	int flags, int width, int precision, int size);
int printf_hex_num(va_list argv, char buffer[],
	int flags, int width, int precision, int size);
int printf_upper_hex(va_list argv, char buffer[],
	int flags, int width, int precision, int size);

int printf_main_hex(va_list argv, char direct[],
char buffer[], int flags, char active_flag, int width, int precision,
int size);

int printf_nprint(va_list argv, char buffer[],
	int flags, int width, int precision, int size);

int printf_pointers(va_list argv, char buffer[],
	int flags, int width, int precision, int size);

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

int printf_strev(va_list argv, char buffer[],
	int flags, int width, int precision, int size);

int printf_rot13(va_list argv, char buffer[],
	int flags, int width, int precision, int size);

int write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_numone(int argv, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_numtwo(int ind, char buffer[], int flags, int width, int precision,
	int len, char separator, char addi);
int write_pointers(char buffer[], int ind, int length,
	int width, int flags, char separator, char addi, int start);

int write_unsigned_num(int negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

int print_chars(char);
int hex_cat(char, char[], int);
int is_digit(char);

long int size_to_num(long int num, int size);
long int size_to_unsign(unsigned long int num, int size);

#endif

