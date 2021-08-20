/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:05:26 by pbielik           #+#    #+#             */
/*   Updated: 2021/06/14 20:28:43 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int		sign;
	int		r;
	int		flag;

	r = 0;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	flag = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		flag++;
		s++;
	}
	if (flag > 1)
		return (0);
	while (*s >= '0' && *s <= '9')
	{
		r = r * 10 + *s - '0';
		s++;
	}
	return (r * sign);
}
