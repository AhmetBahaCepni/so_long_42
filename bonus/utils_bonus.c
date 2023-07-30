/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:39:11 by acepni            #+#    #+#             */
/*   Updated: 2023/07/22 15:27:37 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_over(t_game *game, int is_won)
{
	if (is_won == 1)
	{
		ft_putstr("Game OVER YOU WON! :))\n");
		free_visited(game);
		free_all(game);
        system("leaks so_long_bonus");
		exit(0);
	}
	else if (is_won == 0)
	{
		ft_putstr("Game OVER YOU LOST! :))\n");
		free_visited(game);
		free_all(game);
        system("leaks so_long_bonus");
		exit(0);
	}
}

void	print_floor(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win1,
		game->assets.floor_img, j * 40, i * 40);
}

void	print_objects(t_game *game, int i, int j)
{
	if (game->game_map.map[i][j] == 'C')
	{
		print_floor(game, i, j);
		mlx_put_image_to_window(game->mlx, game->win1,
			game->assets.coin_img, j * 40, i * 40);
	}
	else if (game->game_map.map[i][j] == 'P')
	{
		print_floor(game, i, j);
		mlx_put_image_to_window(game->mlx, game->win1,
			game->assets.player_img, j * 40, i * 40);
	}
	else if (game->game_map.map[i][j] == 'E')
	{
		print_floor(game, i, j);
		mlx_put_image_to_window(game->mlx, game->win1,
			game->assets.exit_img, j * 40, i * 40);
	}
	else if (game->game_map.map[i][j] == 'Q')
		mlx_put_image_to_window(game->mlx, game->win1,
			game->assets.enemy_img, j * 40, i * 40);
}

void	print_map(t_game *game)
{
	char	*s;
	int		i;
	int		j;

	i = -1;
	while (++i < game->game_map.clm)
	{
		j = -1;
		while (++j < game->game_map.row)
		{
			if (game->game_map.map[i][j] == '0')
				print_floor(game, i, j);
			else if (game->game_map.map[i][j] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->win1,
					game->assets.wall_img, j * 40, i * 40);
				s = ft_itoa(game->player.step);
				mlx_string_put(game->mlx, game->win1, 10, 10, 0xFFFFFFFF, s);
				free(s);
			}
			else
				print_objects(game, i, j);
		}
	}
}
