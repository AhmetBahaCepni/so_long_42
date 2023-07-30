/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:52:47 by acepni            #+#    #+#             */
/*   Updated: 2023/07/10 10:22:13 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dfs(int r, int c, int valid_coin, t_game *game)
{
	if (r < 0 || r >= game->game_map.clm || c < 0 || c >= game->game_map.row
		|| game->game_map.visited[r][c] || game->game_map.map[r][c] == '1')
		return (valid_coin);
	if (game->game_map.map[r][c] == 'C')
		valid_coin++;
	game->game_map.visited[r][c] = 1;
	valid_coin = dfs(r - 1, c, valid_coin, game);
	valid_coin = dfs(r + 1, c, valid_coin, game);
	valid_coin = dfs(r, c - 1, valid_coin, game);
	valid_coin = dfs(r, c + 1, valid_coin, game);
	return (valid_coin);
}

void	set_zero(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->game_map.clm)
	{
		j = -1;
		while (++j < game->game_map.row)
			game->game_map.visited[i][j] = 0;
	}
}

int	is_valid_path(t_game *game)
{
	int	valid_coin;
	int	i;

	game->game_map.visited = (int **)malloc(game->game_map.clm * sizeof(int *));
	i = -1;
	while (++i < game->game_map.clm)
		game->game_map.visited[i] = (int *)malloc(game->game_map.row
				* sizeof(int));
	set_zero(game);
	valid_coin = dfs(game->player.pc_y, game->player.pc_x, 0, game);
	if (game->game_map.visited[game->game_map.ex_y][game->game_map.ex_x] == 0
		|| valid_coin != game->total_coins)
		ft_error(game, 44);
	return (1);
}

void	check_map_errors(t_game *game, int *p_count, int *e_count, int index)
{
	int	i;
	int	j;

	i = index / 1000;
	j = index % 1000;
	if (game->game_map.map[i][j] != 'P' && game->game_map.map[i][j] != 'C'
		&& game->game_map.map[i][j] != 'E' && game->game_map.map[i][j] != '1'
		&& game->game_map.map[i][j] != '0')
		ft_error(game, 31);
	if ((i == 0 || i == game->game_map.clm - 1 || j == 0
			|| j == game->game_map.row - 1) && game->game_map.map[i][j] != '1')
		ft_error(game, 32);
	if (game->game_map.map[i][j] == 'P' || game->game_map.map[i][j] == 'E')
	{
		if ((game->game_map.map[i][j] == 'P' && *p_count == 1)
			|| (game->game_map.map[i][j] == 'E' && *e_count == 1))
			ft_error(game, 32);
		else if (game->game_map.map[i][j] == 'P')
			*p_count = *p_count + 1;
		else
			*e_count = *e_count + 1;
	}
}

int	check_map(t_game *game, int p_count, int c_count, int e_count)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->game_map.clm)
	{
		j = -1;
		while (++j < game->game_map.row)
		{
			check_map_errors(game, &p_count, &e_count, (i * 1000) + j);
			if (game->game_map.map[i][j] == 'C')
				c_count++;
		}
	}
	if (c_count == 0 || p_count == 0 || e_count == 0)
		ft_error(game, 30);
	game->total_coins = c_count;
	is_valid_path(game);
	return (1);
}
