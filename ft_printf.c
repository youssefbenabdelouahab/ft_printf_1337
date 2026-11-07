/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-abd <yben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:17:34 by yben-abd          #+#    #+#             */
/*   Updated: 2026/11/07 11:38:59 by yben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_type(char c)
{
	return (c == 'd' || c == 'i' || c == 'x'
		|| c == 'X' || c == 'u' || c == '%'
		|| c == 's' || c == 'c' || c == 'p');
}

static void	handler(char c, va_list *args, int *counter)
{
	if (c == 'd' || c == 'i')
		print_nbr(va_arg(*args, int), counter);
	else if (c == 'x' || c == 'X')
		print_hex(va_arg(*args, unsigned int), c, counter);
	else if (c == 'u')
		print_unbr(va_arg(*args, unsigned int), counter);
	else if (c == 'c')
		printchar(va_arg(*args, int), counter);
	else if (c == '%')
		print_percent(counter);
	else if (c == 'p')
		print_ptr(va_arg(*args, void *), counter);
	else if (c == 's')
		print_str(va_arg(*args, char *), counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		counter;

	if (!format)
		return (-1);
	i = 0;
	counter = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && is_type(format[i + 1]))
		{
			handler(format[i + 1], &ap, &counter);
			i++;
		}
		else
			printchar(format[i], &counter);
		i++;
	}
	va_end(ap);
	return (counter);
}
