/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-abd <yben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 13:17:39 by yben-abd          #+#    #+#             */
/*   Updated: 2026/11/04 17:46:18 by yben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		print_percent(void);
int		printchar(int c);
int		print_str(char *s);
int		print_nbr(int n);
int		print_unbr(unsigned int n);
int		print_hex(unsigned int n, char conv);
int		print_ptr(void *p);

#endif