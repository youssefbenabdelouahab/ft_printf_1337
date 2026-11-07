/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-abd <yben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:22:25 by yben-abd          #+#    #+#             */
/*   Updated: 2026/11/07 13:31:55 by yben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	print_char(int c, int *counter);
void	print_percent(int *counter);
void	print_str(char *s, int *counter);
void	print_nbr(int n, int *counter);
void	print_unbr(unsigned int n, int *counter);
void	print_hex(unsigned int n, char conv, int *counter);
void	print_ptr(void *p, int *counter);
int		ft_printf(const char *format, ...);

#endif
