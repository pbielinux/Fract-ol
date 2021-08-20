/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:13:00 by pbielik           #+#    #+#             */
/*   Updated: 2021/03/08 19:09:09 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t		i;
	char		find;
	const char	*cstr;

	find = (unsigned char)c;
	cstr = (const char *)str;
	i = 0;
	while (i < n)
	{
		if (cstr[i] == find)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
