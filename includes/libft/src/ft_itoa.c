/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:12:13 by pbielik           #+#    #+#             */
/*   Updated: 2021/06/14 20:41:05 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		neg;
	size_t	len;
	char	*tab;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	len = ft_counter(n);
	tab = (char *)malloc(sizeof(char) * len + neg + 1);
	if (!tab)
		return (NULL);
	tab[len + neg] = '\0';
	while (len > 0)
	{
		tab[--len + neg] = n % 10 + 48;
		n /= 10;
	}
	if (neg)
		tab[0] = '-';
	return (tab);
}
