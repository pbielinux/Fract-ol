#include "libft.h"

int	ft_putnbrBase(unsigned long n, char *base)
{
	unsigned int	baseLength;
	int				numLength;

	numLength = 1;
	baseLength = ft_strlen(base);
	if (n == 0)
	{
		write(1, "0", 1);
		return (numLength);
	}
	if (n >= baseLength)
	{
		numLength += ft_putnbrBase(n / baseLength, base);
		write(1, &base[n % baseLength], 1);
	}
	else if (n < baseLength)
		write(1, &base[n], 1);
	return (numLength);
}
