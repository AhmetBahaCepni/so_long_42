/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:04:01 by acepni            #+#    #+#             */
/*   Updated: 2022/10/19 15:04:23 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	end = ft_strlen((char *)s1) - 1;
	while (isset(s1[i], set))
	{
		start++;
		i++;
	}
	i = end;
	while (end >= start && isset(s1[i], set))
	{
		end--;
		i--;
	}
	return (ft_substr(s1, start, end - start + 1));
}
