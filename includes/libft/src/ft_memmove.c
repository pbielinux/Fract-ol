/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:13:38 by pbielik           #+#    #+#             */
/*   Updated: 2021/02/15 19:44:01 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*cdest;
	const char	*csrc;

	cdest = (char *)dest;
	csrc = (const char *)src;
	if (dest <= src)
		return (ft_memcpy(cdest, csrc, n));
	else
	{
		cdest += n;
		csrc += n;
		while (n--)
		{
			*--cdest = *--csrc;
		}
	}
	return (dest);
}
