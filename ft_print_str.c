
#include "ft_printf.h"

static int str_len(char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	print_str(char *s)
{
	int len;
	int ret;

	if (!s)
	{
		ret = write(1, "(null)", 6);
		return (ret);
	}
	len = str_len(s);
	ret = write(1, s, len);
	return (ret);
}
