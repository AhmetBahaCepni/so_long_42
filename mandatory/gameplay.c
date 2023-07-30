/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:57:55 by acepni            #+#    #+#             */
/*   Updated: 2023/07/22 14:01:53 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_movable(int x, int y, t_game *game)
{
	if (game->game_map.map[y][x] == '1')
		return (0);
	if (game->game_map.map[y][x] == 'C')
	{
		game->player.point += 1;
		mlx_put_image_to_window(game->mlx, game->win1,
			game->assets.floor_img, x * 40, y * 40);
	}
	if (game->game_map.map[y][x] == 'E')
	{
		if (game->player.point == game->total_coins)
			game_over(game, 1);
		else
			return (0);
	}
	return (1);
}

int	keys_ad(t_game *game, int key)
{
	if (key == 0 && is_movable(game->player.pc_x - 1, game->player.pc_y, game))
	{
		mlx_destroy_image(game->mlx, game->assets.player_img);
		game->assets.player_img = mlx_xpm_file_to_image(game->mlx,
				"textures/walleL.XPM", &game->xpmx, &game->xpmy);
		game->player.pc_x -= 1;
		game->game_map.map[game->player.pc_y][game->player.pc_x] = 'P';
		return (1);
	}
	else if (key == 2 && is_movable(game->player.pc_x + 1,
			game->player.pc_y, game))
	{
		mlx_destroy_image(game->mlx, game->assets.player_img);
		game->assets.player_img = mlx_xpm_file_to_image(game->mlx,
				"textures/wallee.XPM", &game->xpmx, &game->xpmy);
		game->player.pc_x += 1;
		game->game_map.map[game->player.pc_y][game->player.pc_x] = 'P';
		return (1);
	}
	return (0);
}

int	keys_ws(t_game *game, int key)
{
	if (key == 13 && is_movable(game->player.pc_x, game->player.pc_y - 1, game))
	{
		mlx_destroy_image(game->mlx, game->assets.player_img);
		game->assets.player_img = mlx_xpm_file_to_image(game->mlx,
				"textures/wallee.XPM", &game->xpmx, &game->xpmy);
		game->player.pc_y -= 1;
		game->game_map.map[game->player.pc_y][game->player.pc_x] = 'P';
		return (1);
	}
	else if (key == 1 && is_movable(game->player.pc_x,
			game->player.pc_y + 1, game))
	{
		mlx_destroy_image(game->mlx, game->assets.player_img);
		game->assets.player_img = mlx_xpm_file_to_image(game->mlx,
				"textures/walleL.XPM", &game->xpmx, &game->xpmy);
		game->player.pc_y += 1;
		game->game_map.map[game->player.pc_y][game->player.pc_x] = 'P';
		return (1);
	}
	return (0);
}

int	key_win1(int key, t_game *game)
{
	int	flag;

	flag = 0;
	if (key == 13 || key == 0 || key == 1 || key == 2)
	{
		game->player.step++;
		game->game_map.map[game->player.pc_y][game->player.pc_x] = '0';
		if (key == 0 || key == 2)
			flag = keys_ad(game, key);
		else if (key == 13 || key == 1)
			flag = keys_ws(game, key);
		if (flag == 0)
		{
			game->game_map.map[game->player.pc_y][game->player.pc_x] = 'P';
			game->player.step--;
		}
		else
			ft_putstep(game);
	}
	else if (key == 53)
		exit_key(game);
	print_map(game);
	return (1);
}

int	exit_key(t_game *game)
{
	free_all(game);
	free_visited(game);
	exit(0);
}
