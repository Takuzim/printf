#include <stdarg.h>
#include <stdio.h>
#include <string.h>  // Add this line to include string.h
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int len = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && *(format + 1) == 'r')
        {
            format += 2;  // Skip '%r'
            const char *str = va_arg(args, const char *);

            // Print the reversed string
            for (int i = 0; i < strlen(str); i++)  // Use < instead of !=
            {
                putchar(str[strlen(str) - 1 - i]);
                len++;
            }
        }
        else if (*format == '%')
        {
            format++;
            // Handle other format specifiers here
        }
        else
        {
            putchar(*format);
            len++;
        }

        format++;
    }

    va_end(args);
    return len;
}

int main(void)
{
    // ... other code ...

    _printf("Unknown:[%r]\n", "hello");
    printf("Unknown:[%s]\n", "hello");

    // ... rest of the code ...

    return 0;  // Add a return statement to indicate success
}

