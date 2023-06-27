#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/
 
_putchar - Writes a character*@c:character to write.
Return:success
*/
int _putchar(char c)
{
        return (write(1, &c, 1));
}

/
 
print_char - Prints a single char
@args:va_list containing argument.
@counter: Pointer to counter of characters
*/
void print_char(va_list args, int counter)
{
        char ch = va_arg(args, int);

        _putchar(ch);
        (counter)++;
}

/
 
print_string - Prints a string.
@args:va_list containing arguments.
@counter: Pointer count of characters
*/
void print_string(va_list args, int counter)
{
        charstr = va_arg(args, char );

        if (str != NULL)
        {
                while (str)
                {
                        _putchar(str);
                        (counter)++;
                        str++;
                }
        }
}

/
 
_printf - output according to format.
@format:format string.
Return:number of characters printed
*/
int _printf(const char format, ...)
{
        va_list args;
        int counter = 0;

        va_start(args, format);

        while (format)
        {
                if (format == '%')
                {
                        format++;
                        if (format == '\0')
                                break;
                        if (format == '%')
                        {
                                _putchar('%');
                                counter++;
                        }
                        else if (format == 'c')
                                print_char(args, &counter);
                        else if (format == 's')
                                print_string(args, &counter);
                }
                else
                {
                        _putchar(format);
                        counter++;
                }

                format++;
        }

        va_end(args);

        return (counter);
}
