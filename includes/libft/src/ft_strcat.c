#include "libft.h"

char	*ft_strcat(char	*dst, const char	*src)
{
	char	*ptr;

	ptr = dst + ft_strlen(src);
	while (*src != '\0')
		*ptr++ = *src++;
	*ptr = '\0';
	return (dst);
}
