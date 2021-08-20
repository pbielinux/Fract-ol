/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:21:14 by pbielik           #+#    #+#             */
/*   Updated: 2021/06/14 20:23:16 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*found;
	const char	*pnt;

	c = (unsigned char)c;
	if (c == '\0')
		return (ft_strchr(s, c));
	found = NULL;
	pnt = ft_strchr(s, c);
	while (pnt != NULL)
	{
		found = pnt;
		s = pnt + 1;
		pnt = ft_strchr(s, c);
	}
	return ((char *)found);
}
