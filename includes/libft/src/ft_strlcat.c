/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:34:15 by pbielik           #+#    #+#             */
/*   Updated: 2021/08/03 21:51:24 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t maxlen)
{
	size_t	srclen;
	size_t	destlen;

	srclen = ft_strlen(src);
	destlen = ft_strnlen(dest, maxlen);
	if (destlen == maxlen)
		return (maxlen + srclen);
	if (srclen < (maxlen - destlen))
		ft_memcpy((dest + destlen), src, srclen + 1);
	else
	{
		ft_memcpy((dest + destlen), src, (maxlen - destlen - 1));
		dest[(maxlen - 1)] = '\0';
	}
	return (destlen + srclen);
}
