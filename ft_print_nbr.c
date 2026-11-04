/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-abd <yben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:17:13 by yben-abd          #+#    #+#             */
/*   Updated: 2026/11/04 17:36:43 by yben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int n)
{
	int		count;
	char	c;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		count += print_nbr(n / 10);
	c = (n % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}

int	print_unbr(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += print_nbr(n / 10);
	c = (n % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}
