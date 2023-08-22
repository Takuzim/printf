#include "main.h"

/**
 * get_flags - Determine active flags
 * @format: Formatted string containing the arguments
 * @i: Current index in the format string
 * Return: Flags indicating active options
 */
int get_flags(const char *format, int *i)
{
    /* - + 0 # ' ' */
    /* 1 2 4 8 16 */
    int j, curr_i;
    int flags = 0;
    const char FLAG_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
    const int FLAG_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

    for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
    {
        for (j = 0; FLAG_CHARS[j] != '\0'; j++)
        {
            if (format[curr_i] == FLAG_CHARS[j])
            {
                flags |= FLAG_VALUES[j];
                break;
            }
        }

        if (FLAG_CHARS[j] == 0)
            break;
    }

    *i = curr_i - 1;

    return (flags);
}

