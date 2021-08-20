/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:21:31 by pbielik           #+#    #+#             */
/*   Updated: 2021/06/14 20:26:59 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	unsigned int	beg;
	unsigned int	end;
	char			*trim;

	if (!s1 || !set)
		return (NULL);
	beg = 0;
	while (s1[beg] && ft_strchr(set, s1[beg]))
		beg++;
	end = ft_strlen(s1 + beg);
	if (end)
	{
		while (s1[beg + end - 1] != 0 && ft_strchr(set, s1[beg + end - 1]) != 0)
			end--;
	}
	trim = malloc(sizeof(char) * end + 1);
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, s1 + beg, end + 1);
	trim[end] = '\0';
	return (trim);
}
