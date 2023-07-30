/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:48:45 by acepni            #+#    #+#             */
/*   Updated: 2023/07/10 11:13:51 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_game *game, int err_no)
{
	if (err_no == 0)
		ft_putstr("You could enter only 1 argument to the program\n");
	else if (err_no == 1)
		ft_putstr("Filename wrong or file does not exist\n");
	else if (err_no == 2)
		ft_putstr("Wrong file type (only .ber maps allowed)\n");
	else if (err_no == 30)
		ft_putstr("Coin, player or exit is missing\n");
	else if (err_no == 31)
		ft_putstr("There are strange characters on map\n");
	else if (err_no == 32)
		ft_putstr("Map is incomplete (fill the borders)\n");
	else if (err_no == 33)
		ft_putstr("Player or exit is given multiple times on map\n");
	else if (err_no == 44)
		ft_putstr("Map is impossible to finish\n");
	if (err_no != 0 && err_no != 1 && err_no != 2)
		free_all(game);
	if (err_no == 44)
		free_visited(game);
	exit(0);
}

void	check_for_file(t_game *game, char *filename, int fd)
{
	int	len;

	len = ft_strlen(filename);
	if (fd == -1)
		ft_error(game, 1);
	if (filename[len - 1] != 'r' || filename[len - 2] != 'e'
		|| filename[len - 3] != 'b' || filename[len - 4] != '.')
		ft_error(game, 2);
}
