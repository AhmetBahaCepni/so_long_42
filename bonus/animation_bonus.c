/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:59:00 by acepni            #+#    #+#             */
/*   Updated: 2023/07/20 15:19:25 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	sprite(t_game *game)
{
	static int	i;

	print_map(game);
	mlx_destroy_image(game->mlx, game->assets.enemy_img);
	mlx_destroy_image(game->mlx, game->assets.coin_img);
	if (i < 50)
	{
		game->assets.enemy_img = mlx_xpm_file_to_image(game->mlx,
				"textures/enemy2.XPM", &game->xpmx, &game->xpmy);
		game->assets.coin_img = mlx_xpm_file_to_image(game->mlx,
				"textures/coin.XPM", &game->xpmx, &game->xpmy);
	}
	else
	{
		game->assets.enemy_img = mlx_xpm_file_to_image(game->mlx,
				"textures/enemy1.XPM", &game->xpmx, &game->xpmy);
		game->assets.coin_img = mlx_xpm_file_to_image(game->mlx,
				"textures/coin2.XPM", &game->xpmx, &game->xpmy);
	}
	if (i == 100)
		i = 0;
	i++;
	return (1);
}
