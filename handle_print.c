#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @fm: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @cuffer: Buffer array to handle print.
 * @f: Calculates active flags
 * @width: get width.
 * @automate: Precision specification
 * @s: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char cuffer[],
int f, int width, int automate, int s)
{
int i, unknow_len = 0, printed_chars = -1;
fm_t fm_types[] = {
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'i', print_int}, {'d', print_int}, {'b', print_binary},
{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
};
for (i = 0; fm_types[i].fm != '\0'; i++)
if (fm[*ind] == fmt_types[i].fm)
return (fm_types[i].fn(list, cuffer, f, width, automate, s));

if (fm_types[i].fm == '\0')
{
if (fm[*ind] == '\0')
return (-1);
unknow_len += write(1, "%%", 1);
if (fm[*ind - 1] == ' ')
unknow_len += write(1, " ", 1);
else if (width)
{
--(*ind);
while (fm[*ind] != ' ' && fm[*ind] != '%')
--(*ind);
if (fm[*ind] == ' ')
--(*ind);
return (1);
}
unknow_len += write(1, &fm[*ind], 1);
return (unknow_len);
}
return (printed_chars);
}
