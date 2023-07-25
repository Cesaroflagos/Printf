#include "main.h"
void print_cufffer(char cuffer[], int *cuff_ind);

/**
 * _printf - Starting point
 * @format: format
 * Return: printed chars
 */
int _printf(const char *format, ...)
{
int c, pr = 0, pr_chars = 0;
int f, width, automate, s, cuff_ind = 0;
va_list list;
char cuffer[BUFF_SIZE];

if (format == NULL)
return (-1);
va_start(list, format);

for (c = 0; format && format[c] != '\0'; c++)
{
if (format[c] != '%')
{
cuffer[cuff_ind++] = format[c];

if (cuff_ind == BUFF_SIZE)
print_cuffer(cuffer, &cuff_ind);

/* write(1, &format[c], 1);*/
pr_chars++;
}
else
{
print_cuffer(cuffer, &cuff_ind);
f = get_f(format, &c);
width = get_width(format, &c, list);
automate = get_automate(format, &c, list)
s = get_s(format, &c);
c++;
printed = handle_print(format, &c, list,
cuffer, f, width, automate, s);

if (printed == -1)
return (-1);
printed_chars += printed;
}
}
print_cuffer(cuffer, &cuff_ind);
va_end(list);
return (printed_chars);
}

/**
 * print_cuffer - Starting point
 * @cuffer: array
 * @cuff_ind: index of chars
 * Return:
 */
void print_cuffer(char cuffer[], int *cuff_ind)
{
if (*cuff_ind > 0)
write(1, &cuffer[0], *cuff_ind);

*cuff_ind = 0;
}
