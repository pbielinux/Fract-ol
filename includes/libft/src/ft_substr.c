/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:22:02 by pbielik           #+#    #+#             */
/*   Updated: 2021/06/14 20:25:07 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	min_len;
	char			*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len <= 0)
		return (ft_strdup(""));
	else
	{
		min_len = ft_strlen(&s[start]);
		if (min_len < len)
			len = min_len;
		sub = malloc(sizeof(char) * len + 1);
		if (!sub)
			return (NULL);
		i = start;
		while (s[i] && (i - start) < len)
		{
			sub[i - start] = s[i];
			i++;
		}
		sub[i - start] = '\0';
	}
	return (sub);
}
