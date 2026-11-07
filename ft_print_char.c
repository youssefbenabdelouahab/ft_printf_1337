/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-abd <yben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:23:38 by yben-abd          #+#    #+#             */
/*   Updated: 2026/11/07 13:04:37 by yben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(int c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

void	print_percent(int *counter)
{
	write(1, "%", 1);
	(*counter)++;
}
