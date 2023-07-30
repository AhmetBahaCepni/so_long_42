/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:03:23 by acepni            #+#    #+#             */
/*   Updated: 2022/10/19 15:03:30 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	destsize;
	size_t	srcsize;

	destsize = (ft_strlen(dst));
	srcsize = (ft_strlen(src));
	i = destsize;
	if (size <= destsize)
		return (size + srcsize);
	j = 0;
	while (src[j] != '\0' && j < size - destsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (destsize + srcsize);
}
