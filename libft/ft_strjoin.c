/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:03:21 by acepni            #+#    #+#             */
/*   Updated: 2022/10/19 15:03:30 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*comb;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	comb = malloc(len1 + len2 + 1);
	if (!comb)
		return (0);
	i = -1;
	while (s1[++i])
		comb[i] = ((char *)s1)[i];
	i--;
	while (s2[++i - len1])
		comb[i] = ((char *)s2)[i - len1];
	comb[i] = 0;
	return (comb);
}
