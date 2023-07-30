/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:54:38 by acepni            #+#    #+#             */
/*   Updated: 2023/07/22 13:57:04 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	ft_putstep(t_game *game)
{
	char	*step;

	step = ft_itoa(game->player.step);
	ft_putstr("step: ");
	ft_putstr(step);
	ft_putstr("\n");
	free(step);
}

void	assign_coords(t_game *game, int i, int j)
{
	if (game->game_map.map[i][j] == 'P')
	{
		game->player.pc_x = j;
		game->player.pc_y = i;
	}
	else if (game->game_map.map[i][j] == 'C')
		game->total_coins++;
	else if (game->game_map.map[i][j] == 'E')
	{
		game->game_map.ex_x = j;
		game->game_map.ex_y = i;
	}
}

void	get_coords(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->game_map.clm)
	{
		j = -1;
		while (++j < game->game_map.row)
			assign_coords(game, i, j);
	}
}

void	fill_struct(t_game *game)
{
	get_coords(game);
	game->player.point = 0;
	game->player.step = 0;
	game->assets.floor_img = mlx_xpm_file_to_image(game->mlx,
			"textures/stone.XPM", &game->xpmx, &game->xpmy);
	game->assets.player_img = mlx_xpm_file_to_image(game->mlx,
			"textures/wallee.XPM", &game->xpmx, &game->xpmy);
	game->assets.coin_img = mlx_xpm_file_to_image(game->mlx,
			"textures/coin2.XPM", &game->xpmx, &game->xpmy);
	game->assets.wall_img = mlx_xpm_file_to_image(game->mlx,
			"textures/box.XPM", &game->xpmx, &game->xpmy);
	game->assets.exit_img = mlx_xpm_file_to_image(game->mlx,
			"textures/eve.XPM", &game->xpmx, &game->xpmy);
}
