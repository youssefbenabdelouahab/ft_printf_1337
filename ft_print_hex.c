/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-abd <yben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:17:09 by yben-abd          #+#    #+#             */
/*   Updated: 2026/11/04 17:48:48 by yben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_nbr_base(unsigned int n, const char *digits)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 16)
	{
		count += put_nbr_base((n / 16), digits);
	}
	c = digits[n % 16];
	count += write(1, &c, 1);
	return (count);
}

int	print_hex(unsigned int n, char conv)
{
	char	*base;

	if (conv == 'x')
	{
		base = "0123456789abcdef";
		return (put_nbr_base(n, base));
	}
	else if (conv == 'X')
	{
		base = "0123456789ABCDEF";
		return (put_nbr_base(n, base));
	}
	else
		return (-1);
}

int	print_ptr(void *p)
{
	int	ret;

	ret = 0;
	if (p == NULL)
		return (write(1, "(nil)", 5));
	ret += write(1, "0x", 2);
	ret += put_nbr_base(p, "0123456789abcdef");
	return (ret);
}
