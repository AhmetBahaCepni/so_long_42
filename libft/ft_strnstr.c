/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:03:57 by acepni            #+#    #+#             */
/*   Updated: 2022/10/19 15:04:23 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_check(const char *big, const char *little, size_t i, size_t len)
{
	size_t	j;

	j = 0;
	while (little[j] != '\0')
	{
		if (little[j] != big[i] || !(i < len))
			return (0);
		i++;
		j++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!big && len == 0)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		if (big[i] == little[0] && i < len)
		{
			if (my_check(big, little, i, len))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
