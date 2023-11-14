#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @x: string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *x)
{
	int i = 0;
	unsigned long int result = 0;

	if (*x == '+')
		x++;  /* TODO: why does this make main return 255? */
	for (i = 0;  x[i] != '\0'; i++)
	{
		if (x[i] >= '0' && x[i] <= '9')
		{
			result *= 10;
			result += (x[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @inp: input
 * @fdt: filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int inp, int fdt)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fdt == STDERR_FILENO)
		__putchar = _eputchar;
	if (inp < 0)
	{
		_abs_ = -inp;
		__putchar('-');
		count++;
	}
	else
		_abs_ = inp;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @bas: base
 * @flg: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int bas, int flg)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *poi;
	unsigned long n = num;

	if (!(flg & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flg & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	poi = &buffer[49];
	*poi = '\0';

	do	{
		*--poi = array[n % bas];
		n /= bas;
	} while (n != 0);

	if (sign)
		*--poi = sign;
	return (poi);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @abc: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *abc)
{
	int i;

	for (i = 0; abc[i] != '\0'; i++)
		if (abc[i] == '#' && (!i || abc[i - 1] == ' '))
		{
			abc[i] = '\0';
			break;
		}
}
