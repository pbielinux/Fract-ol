/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:20:28 by pbielik           #+#    #+#             */
/*   Updated: 2021/06/14 20:11:00 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	str2_len;

	if (*str2 == '\0')
		return ((char *)str1);
	str2_len = ft_strlen(str2);
	while (*str1 != '\0' && n-- >= str2_len)
	{
		if (*str1 == *str2 && !ft_memcmp(str1, str2, str2_len))
			return ((char *)str1);
		str1++;
	}
	return (NULL);
}
