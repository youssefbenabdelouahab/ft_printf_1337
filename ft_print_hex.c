/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-abd <yben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:17:09 by yben-abd          #+#    #+#             */
/*   Updated: 2026/11/07 11:59:19 by yben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_nbr_base(unsigned long n, const char *digits, int *counter)
{
	char	c;

	if (n >= 16)
		put_nbr_base((n / 16), digits, counter);
	c = digits[n % 16];
	write(1, &c, 1);
	(*counter)++;
}

void	print_hex(unsigned int n, char conv, int *counter)
{
	char			*base;
	unsigned long	nb;

	nb = (unsigned long)n;
	if (conv == 'x')
	{
		base = "0123456789abcdef";
		put_nbr_base(nb, base, counter);
	}
	else if (conv == 'X')
	{
		base = "0123456789ABCDEF";
		put_nbr_base(nb, base, counter);
	}
	else
		*counter = -1;
}

void	print_ptr(void *p, int *counter)
{
	unsigned long	ptr;

	ptr = (unsigned long)p;
	if (p == NULL)
	{
		write(1, "(nil)", 5);
		*counter += 5;
		return ;
	}
	write(1, "0x", 2);
	*counter += 2;
	put_nbr_base(ptr, "0123456789abcdef", counter);
}
