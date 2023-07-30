/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:11:36 by acepni            #+#    #+#             */
/*   Updated: 2023/07/22 14:02:58 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlenn(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchrr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s3;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(ft_strlenn(s1) + ft_strlenn(s2) + 1);
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i] != 0)
		s3[i] = s1[i];
	j = -1;
	while (s2[++j] != 0)
	{
		s3[i + j] = s2[j];
	}
	s3[i + j] = 0;
	free(s1);
	return (s3);
}

int	count_lines(int fd, int *line_len)
{
	int		r;
	int		count;
	int		flag;
	char	my_char;

	count = 0;
	r = read(fd, &my_char, 1);
	while (r != 0 && r != -1)
	{
		flag = 0;
		if (count == 0)
			*line_len = *line_len + 1;
		if (my_char == '\n')
		{
			count++;
			flag = 1;
		}
		r = read(fd, &my_char, 1);
	}
	if (flag != 1)
		count++;
	*line_len = *line_len - 1;
	return (count);
}
