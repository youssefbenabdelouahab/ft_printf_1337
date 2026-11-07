/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-abd <yben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:51:16 by yben-abd          #+#    #+#             */
/*   Updated: 2026/11/07 13:00:35 by yben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_nbr_base(unsigned long n, char *digits, int *counter)
{
	char	c;

	if (n >= 16)
		print_nbr_base((n / 16), digits, counter);
	c = digits[n % 16];
	write(1, &c, 1);
	(*counter)++;
}

void	print_hex(unsigned int n, char conv, int *counter)
{
	unsigned long	nb;

	nb = (unsigned long) n;
	if (conv == 'x')
		print_nbr_base(nb, "0123456789abcdef", counter);
	else if (conv == 'X')
		print_nbr_base(nb, "0123456789ABCDEF", counter);
}

void	print_ptr(void *p, int *counter)
{
	unsigned long	ptr;

	ptr = (unsigned long) p;
	if (p == NULL)
	{
		write(1, "(nil)", 5);
		(*counter) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*counter) += 2;
	print_nbr_base(ptr, "0123456789abcdef", counter);
}
