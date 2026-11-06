/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-abd <yben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:17:39 by yben-abd          #+#    #+#             */
/*   Updated: 2026/11/06 19:09:29 by yben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	print_percent(int *counter);
void	printchar(int c, int *counter);
void	print_str(char *s, int *counter);
void	print_nbr(int n, int *counter);
void	print_unbr(unsigned int n, int *counter);
void	print_hex(unsigned int n, char conv, int *counter);
void	print_ptr(void *p, int *counter);

#endif