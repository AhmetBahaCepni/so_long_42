/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:59:57 by acepni            #+#    #+#             */
/*   Updated: 2023/07/22 14:03:18 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_error(&game, 0);
	fill_map(argv[1], &game);
	game.mlx = mlx_init();
	game.win1 = mlx_new_window(game.mlx, game.game_map.row * 40,
			game.game_map.clm * 40, "So_Long");
	fill_struct(&game);
	check_map(&game, 0, 0, 0);
	print_map(&game);
	mlx_key_hook(game.win1, key_win1, &game);
	mlx_hook(game.win1, 17, 1L << 17, exit_key, &game);
	mlx_loop(game.mlx);
	return (0);
}
