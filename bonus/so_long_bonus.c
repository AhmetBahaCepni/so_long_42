/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:19:10 by acepni            #+#    #+#             */
/*   Updated: 2023/07/20 15:22:29 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	mlx_loop_hook(game.mlx, &sprite, &game);
	mlx_loop(game.mlx);
	return (0);
}
