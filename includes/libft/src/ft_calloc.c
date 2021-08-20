/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:06:22 by pbielik           #+#    #+#             */
/*   Updated: 2021/06/14 20:28:00 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t n_size)
{
	void	*ptr;

	ptr = malloc(n * n_size);
	if (ptr == 0)
		return (ptr);
	ft_bzero(ptr, n * n_size);
	return (ptr);
}
