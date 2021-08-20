/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:44:18 by pbielik           #+#    #+#             */
/*   Updated: 2021/06/14 20:26:00 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_counter(int n)
{
	size_t	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}
