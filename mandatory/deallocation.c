/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:20:53 by acepni            #+#    #+#             */
/*   Updated: 2023/07/22 14:01:46 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->game_map.clm)
	{
		free(game->game_map.map[i]);
		i++;
	}
	free(game->game_map.map);
}

void	free_visited(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->game_map.clm)
	{
		free(game->game_map.visited[i]);
		i++;
	}
	free(game->game_map.visited);
}

void	free_assets(t_game *game)
{
	mlx_destroy_image(game->mlx, game->assets.floor_img);
	mlx_destroy_image(game->mlx, game->assets.player_img);
	mlx_destroy_image(game->mlx, game->assets.coin_img);
	mlx_destroy_image(game->mlx, game->assets.wall_img);
	mlx_destroy_image(game->mlx, game->assets.exit_img);
}

void	free_all(t_game *game)
{
	free_map(game);
	free_assets(game);
	mlx_destroy_window(game->mlx, game->win1);
}
