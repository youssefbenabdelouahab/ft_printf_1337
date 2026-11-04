#include "ft_printf.h"


int	print_nbr(int n)
{
	int count;
	char c;

	count = 0;
	if (n == -2147483648)
	{
		count = write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		print_nbr(n / 10);
		print_nbr(n % 10);
	}
	c = n + '0';
	count += write(1, &c, 1);
	return(count);
}

// int print_unbr(unsigned int n)
// {
	
// }


int main()
{
	int a = print_nbr(297);
	int b = print_nbr(0);
	int c = print_nbr(-2147483648);
	int d = print_nbr(-123456789);

	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", d);
}