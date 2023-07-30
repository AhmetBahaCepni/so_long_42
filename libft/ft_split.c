/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:03:14 by acepni            #+#    #+#             */
/*   Updated: 2022/10/19 15:46:43 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_letters(const char *str, char c, int i)
{
	int	temp;
	int	count;

	count = 0;
	temp = i;
	while (str[temp] != c && str[temp])
	{
		count++;
		temp++;
	}
	if ((size_t)i > ft_strlen(str) - 1)
		return (NULL);
	return (ft_substr(str, i, count));
}

static int	count_words(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

char	**ft_split(const char *str, char c)
{
	int		count;
	int		i;
	int		word_c;
	char	**split;

	count = 0;
	i = 0;
	word_c = count_words(str, c);
	split = (char **)malloc(sizeof(char *) * (word_c + 1));
	if (!split)
		return (0);
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		split[count++] = get_letters(str, c, i);
		while (str[i] != c && str[i])
			i++;
	}
	if (count == word_c)
		split[count] = NULL;
	return (split);
}
