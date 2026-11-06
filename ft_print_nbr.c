/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-abd <yben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:17:13 by yben-abd          #+#    #+#             */
/*   Updated: 2026/11/06 19:11:32 by yben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_nbr(int n, int *counter)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*counter = 11;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		(*counter)++;
		n = -n;
	}
	if (n >= 10)
		print_nbr(n / 10, counter);
	c = (n % 10) + '0';
	write(1, &c, 1);
	(*counter)++;
}

void	print_unbr(unsigned int n, int *counter)
{
	char	c;

	if (n >= 10)
		print_unbr(n / 10, counter);
	c = (n % 10) + '0';
	write(1, &c, 1);
	(*counter)++;
}
