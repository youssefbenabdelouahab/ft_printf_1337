/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-abd <yben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:17:34 by yben-abd          #+#    #+#             */
/*   Updated: 2026/11/06 12:05:57 by yben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int handler(char c, va_list *args)
{
    int count;

    count = 0;
    if (c == 'd' || c == 'i')
        count += print_nbr(va_arg(*args, int));
    else if (c == 'x' || c == 'X')
        count += print_hex(va_arg(*args, unsigned int), c);
    else if (c == 'u')
        count += print_unbr(va_arg(*args, unsigned int));
    else if (c == 'c')
        count += printchar(va_arg(*args, int));
    else if (c == '%')
        count += print_percent();
    else if (c == 'p')
        count += print_ptr(va_arg(*args, void *));
    else if (c == 's')
        count += print_str(va_arg(*args, char *));
    return (count);
}

int		ft_printf(const char *format, ...)
{
    va_list ap;
    int i;
    int count;

    i = 0;
    count = 0;
    va_start(ap, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            count += handler(format[i + 1], &ap);
            i++;
        }
        else
            printchar(format[i]);
        i++;
    }
    va_end(ap);
    return (count);
}