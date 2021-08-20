#include "libft.h"

int	ft_numLengthBase(unsigned long n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += 1;
		return (count);
	}
	while (n > 0)
	{
		count++;
		n /= base;
	}
	return (count);
}
