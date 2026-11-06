/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-abd <yben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:17:03 by yben-abd          #+#    #+#             */
/*   Updated: 2026/11/06 19:10:02 by yben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printchar(int c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

void	print_percent(int *counter)
{
	write(1, "%", 1);
	(*counter)++;
}
