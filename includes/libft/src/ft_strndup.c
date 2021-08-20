/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:20:13 by pbielik           #+#    #+#             */
/*   Updated: 2021/06/14 20:27:39 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*copy;

	copy = (char *)malloc(sizeof(char) * n + 1);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, str, n);
	copy[n] = '\0';
	return (copy);
}
