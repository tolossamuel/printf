#include "main.h"

/**
 * _printf - functions
 * @format: pointer
 * Return: number
 */
int _printf(const char *format, ...)
{
	unsigned int i, s_len;
	unsigned int count = 0;

	va_list list;

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count += 1;
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			_putchar(va_arg(list, int));
			i++;
		}
		else if (format[i + 1] == 's')
		{
			s_len = len(va_arg(list, char *));
			count += s_len;
			i++;
		}
		else if (format[i + 1] == '%')
		{
			_putchar('%');
			i++;
		}
		va_end(list);
	}
	return (count);
}
