#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Starting point
 * @types: List a of arguments
 * @cuffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @width: Width
 * @automate: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
int f, int width, int automate, int s)
{
char c = va_arg(types, int);

return (handle_write_char(c, cuffer, f, width, automate, s));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Starting point
 * @types: List a of arguments
 * @cuffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @width: get width.
 * @automate: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char cuffer[],
int f, int width, int automate, int s)
{
int length = 0, i;
char *str = va_arg(types, char *);

UNUSED(cuffer);
UNUSED(f);
UNUSED(width);
UNUSED(automate);
UNUSED(s);
if (str == NULL)
{
str = "(null)";
if (automate >= 6)
str = "      ";
}

while (str[length] != '\0')
length++;

if (automate >= 0 && automate < length)
length = automate;

if (width > length)
{
if (f & F_MINUS)
{
write(1, &str[0], length);
for (i = width - length; i > 0; i--)
write(1, " ", 1);
return (width);
}
else
{
for (i = width - length; i > 0; i--)
write(1, " ", 1);
write(1, &str[0], length);
return (width);
}
}
return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Starting point
 * @types: List of arguments
 * @cuffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @width: get width.
 * @automate: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char cuffer[],
int f, int width, int automate, int s)
{
UNUSED(types);
UNUSED(cuffer);
UNUSED(f);
UNUSED(width);
UNUSED(automate);
UNUSED(s);
return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Starting point
 * @types: List of arguments
 * @cuffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @width: get width.
 * @automate: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char cuffer[],
int f, int width, int automate, int s)
{
int i = BUFF_SIZE - 2;
int is_negative = 0;
long int n = va_arg(types, long int);
unsigned long int num;

n = convert_size_number(n, s);

if (n == 0)
buffer[i--] = '0';
cuffer[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)n;

if (n < 0)
{
num = (unsigned long int)((-1) * n);
is_negative = 1;
}

while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
i++;

return (write_number(is_negative, i, cuffer, f, width, automate, s));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Starting point
 * @types: List of arguments
 * @cuffer: Buffer array to handle print
 * @f:  Calculates active flags
 * @width: get width.
 * @automate: Precision specification
 * @s: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char cuffer[],
int f, int width, int automate, int s)
{
unsigned int n, m, i, p;
unsigned int a[32];
int count;

UNUSED(cuffer);
UNUSED(f);
UNUSED(width);
UNUSED(automate);
UNUSED(s);

n = va_arg(types, unsigned int);
m = 2147483648; /* (2 ^ 31) */
a[0] = n / m;
for (i = 1; i < 32; i++)
{
m /= 2;
a[i] = (n / m) % 2;
}
for (i = 0, p = 0, count = 0; i < 32; i++)
{
p += a[i];
if (p || i == 31)
{
char z = '0' + a[i];

write(1, &z, 1);
count++;
}
}
return (count);
}
