/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:03:51 by acepni            #+#    #+#             */
/*   Updated: 2022/10/19 15:03:51 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;
	size_t	len;

	len = ft_strlen((char *)s);
	new = malloc(len + 1);
	if (!new)
		return (0);
	i = 0;
	while (i < len)
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = 0;
	return (new);
}
