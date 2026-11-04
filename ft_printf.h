#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		print_percent(void);
int		printchar(int c);
int		print_str(char *s);
int		print_nbr(int n);
int		print_unbr(unsigned int n);



#endif