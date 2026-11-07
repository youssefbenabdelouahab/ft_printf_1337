/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-abd <yben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:27:20 by yben-abd          #+#    #+#             */
/*   Updated: 2026/11/07 13:05:12 by yben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	str_len(char *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

void	print_str(char *s, int *counter)
{
	int	len;

	if (!s)
	{
		write(1, "(null)", 6);
		(*counter) += 6;
		return ;
	}
	len = str_len(s);
	write (1, s, len);
	(*counter) += len;
}
