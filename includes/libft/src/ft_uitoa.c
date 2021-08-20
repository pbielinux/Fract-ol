#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	char	*a;
	int		len;

	len = ft_numLength(n);
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	a[len--] = '\0';
	if (n == 0)
		a[len] = 0 + '0';
	while (n > 0)
	{
		a[len--] = n % 10 + '0';
		n /= 10;
	}
	return (a);
}
