/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:17:44 by acepni            #+#    #+#             */
/*   Updated: 2023/07/20 15:29:50 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_putten(char *putline)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (putline[i] != '\0' && putline[i] != '\n')
		i++;
	if (!putline[i])
	{
		free(putline);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlenn(putline) - i));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (putline[i + j] != '\0')
	{
		str[j] = putline[j + i];
		j++;
	}
	str[j] = '\0';
	free(putline);
	return (str);
}

char	*get_main_line(char *putline)
{
	int		i;
	char	*str;

	i = 0;
	if (!putline[i])
		return (NULL);
	while (putline[i] != '\0' && putline[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (putline[i] != '\0' && putline[i] != '\n')
	{
		str[i] = putline[i];
		i++;
	}
	if (putline[i] == '\n')
	{
		str[i] = putline[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_read(int fd, char *putline)
{
	char	*buff;
	int		reader;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	reader = 1;
	while (!ft_strchrr(putline, '\n') && reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[reader] = '\0';
		putline = ft_strjoinn(putline, buff);
	}
	free(buff);
	return (putline);
}

char	*get_next_line(int fd)
{
	char		*mainline;
	static char	*putline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	putline = get_read(fd, putline);
	if (!putline)
		return (NULL);
	mainline = get_main_line(putline);
	putline = get_putten(putline);
	return (mainline);
}

void	fill_map(char *filename, t_game *game)
{
	char	*temp;
	int		i;
	int		fd;
	int		line_c;
	int		line_len;

	line_len = 0;
	fd = open(filename, O_RDONLY);
	check_for_file(game, filename, fd);
	line_c = count_lines(fd, &line_len);
	game->game_map.clm = line_c;
	game->game_map.row = line_len;
	close(fd);
	fd = open(filename, O_RDONLY);
	i = 0;
	game->game_map.map = (char **)malloc(sizeof(char *) * (line_c + 1));
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		game->game_map.map[i] = temp;
		temp = get_next_line(fd);
		i++;
	}
	close(fd);
}
