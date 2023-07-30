/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:03:15 by acepni            #+#    #+#             */
/*   Updated: 2022/10/19 15:03:15 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	char	*str;
	size_t	i;

	c = c % 256;
	str = (char *)s;
	len = ft_strlen(str);
	i = 0;
	while (i < len + 1)
	{
		if (str[i] == c)
		{
			return (&str[i]);
		}
		i++;
	}
	return (0);
}
