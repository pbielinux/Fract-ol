/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:26:00 by pbielik           #+#    #+#             */
/*   Updated: 2021/06/14 20:19:17 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(const char *str, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			**tab;

	tab = (char **)malloc(sizeof(char *) * (ft_wrdcnt(str, c)) + 1);
	if (!str || !tab)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		j = i;
		while (str[i] && str[i] != c)
			i++;
		if (i > j)
		{
			tab[k] = ft_strndup(str + j, i - j);
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}
