/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:02:41 by acepni            #+#    #+#             */
/*   Updated: 2023/07/22 14:01:39 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_player{
	int	pc_x;
	int	pc_y;
	int	point;
	int	step;
}	t_player;

typedef struct s_assets{
	void	*floor_img;
	void	*player_img;
	void	*coin_img;
	void	*wall_img;
	void	*exit_img;
}	t_assets;

typedef struct s_map{
	char	**map;
	int		**visited;
	int		row;
	int		clm;
	int		ex_x;
	int		ex_y;
}	t_map;

typedef struct s_game{
	t_player	player;
	t_map		game_map;
	t_assets	assets;
	void		*mlx;
	void		*win1;
	int			total_coins;
	int			xpmx;
	int			xpmy;
}	t_game;

// utils.c
void	game_over(t_game *game, int is_won);
void	print_map(t_game *game);

// checker.c
void	ft_error(t_game *game, int err_no);
void	check_for_file(t_game *game, char *filename, int fd);

// check_map.c
int		check_map(t_game *game, int p_count, int c_count, int e_count);
int		dfs(int r, int c, int valid_coin, t_game *game);
int		is_valid_path(t_game *game);

// assign_vars.c
void	fill_struct(t_game *game);
void	get_coords(t_game *game);
void	ft_putstr(char *s);
void	ft_putstep(t_game *game);

// gameplay.c
int		is_movable(int x, int y, t_game *game);
int		key_win1(int key, t_game *game);
int		exit_key(t_game *game);

// deallocation.c
void	free_map(t_game *game);
void	free_visited(t_game *game);
void	free_assets(t_game *game);
void	free_all(t_game *game);

// gnl.c and gnl_utils.c
void	fill_map(char *filename, t_game *game);
size_t	ft_strlenn(const char *s);
char	*ft_strchrr(const char *s, int c);
char	*ft_strjoinn(char *s1, char *s2);
char	*get_main_line(char *putline);
char	*get_putten(char *putline);
char	*get_read(int fd, char *putline);
char	*get_next_line(int fd);
int		count_lines(int fd, int *line_len);

#endif