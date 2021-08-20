/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 20:13:41 by pbielik           #+#    #+#             */
/*   Updated: 2021/06/14 20:13:50 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	size_t	n;

	n = ft_strlen(str2);
	if (*str2 == '\0')
		return ((char *)str1);
	if (n == 0)
		return (NULL);
	while (*str1)
	{
		if (!ft_memcmp(str1, str2, n))
			return ((char *)str1);
		str1++;
	}
	return (NULL);
}
