/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-abd <yben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:17:20 by yben-abd          #+#    #+#             */
/*   Updated: 2026/11/04 14:26:35 by yben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	str_len(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	print_str(char *s)
{
	int	len;
	int	ret;

	if (!s)
	{
		ret = write(1, "(null)", 6);
		return (ret);
	}
	len = str_len(s);
	ret = write(1, s, len);
	return (ret);
}
