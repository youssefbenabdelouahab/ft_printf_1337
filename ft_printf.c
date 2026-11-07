/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-abd <yben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:38:30 by yben-abd          #+#    #+#             */
/*   Updated: 2026/11/07 19:45:55 by yben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_type(char c)
{
	return (c == 'c' || c == 'd' || c == 'i'
		|| c == '%' || c == 'u'
		|| c == 'x' || c == 'X'
		|| c == 'p' || c == 's');
}

static void	handler(char c, va_list *ap, int *counter)
{
	if (c == 'c')
		print_char(va_arg(*ap, int), counter);
	else if (c == '%')
		print_percent(counter);
	else if (c == 'i' || c == 'd')
		print_nbr(va_arg(*ap, int), counter);
	else if (c == 'x' || c == 'X')
		print_hex(va_arg(*ap, unsigned int), c, counter);
	else if (c == 'u')
		print_unbr(va_arg(*ap, unsigned int), counter);
	else if (c == 'p')
		print_ptr(va_arg(*ap, void *), counter);
	else if (c == 's')
		print_str(va_arg(*ap, char *), counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		counter;

	counter = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if ((*format) == '%' && is_type(*(format + 1)))
		{
			handler(*(format + 1), &ap, &counter);
			format++;
		}
		else
		{
			print_char(*format, &counter);
		}
		format++;
	}
	va_end(ap);
	return (counter);
}
