/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-abd <yben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:17:34 by yben-abd          #+#    #+#             */
/*   Updated: 2026/11/04 18:28:53 by yben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_conversion_int(char c, va_list *ap)
{
	int ret;

	ret = 0;
	if (ap[i + 1] == 'd' || ap[i + 1] == 'i')
		ret += print_nbr();
	else if (ap[i + 1] == 'u')
		ret += print_unbr();
	else if (ap[i + 1] == 'x' || ap[i+1] == 'X')
		ret += print_hex();
	return (ret)
}

static int handle_conversion_str(char c, va_list *ap)
{
	if (ap[i + 1] == 'c')
		ret += print_char();
	else if (ap[i + 1] == 's')
		ret += print_str();
	else if (ap[i+1] == 'p')
		ret += print_ptr();
	else if (ap[i+1] == '%')
		ret += printpercent();
}

static int handle_conversion(char c, va_list *ap)
{
	int ret;

	ret	= 0;
	while(ap[i] != '\0')
	{
		if (ap[i] == '%')
		{
			if (ap[i] == 'c' || ap[i] == 's' || ap[i] == 'p' || ap[i] == '%')
				ret += handle_conversion_str(c, ap);
			else if (ap[i] == 'd' || ap[i] == 'i' || ap[i] == 'u' || ap[i] == 'x' || || ap[i] == 'X')
				ret += handle_conversion_int(c, ap);
			else 
				return (-1);
		}
		i++;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	va_end(ap);
	return (0);
}
