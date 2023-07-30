/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:03:59 by acepni            #+#    #+#             */
/*   Updated: 2022/10/19 15:03:59 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*str;
	char	*last;
	size_t	i;

	last = 0;
	str = (char *)s;
	len = ft_strlen(str);
	c = c % 256;
	i = 0;
	while (i < len + 1)
	{
		if (str[i] == c)
		{
			last = &str[i];
		}
		i++;
	}
	return (last);
}
