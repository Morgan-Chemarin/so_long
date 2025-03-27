/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:30:02 by dev               #+#    #+#             */
/*   Updated: 2025/03/27 17:11:22 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include "../get-next-line/get_next_line.h"
# include "../ft_printf/ft_printf.h"

# define TILE_SIZE 64

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
	int		moves;
	t_map	*map;
}	t_game;

//render.c
void	*load_texture(void *mlx, char *path);
int		init_game(t_game *game, t_map *map);
void	put_tile_image(t_game *game, char tile, int x, int y);
void	render_map(t_game *game);

//free_and_close.c
void	free_map(t_map *map);
void	free_textures(t_game *game);
int		close_game(t_game *game);

//controls.c
int		can_move(t_game *game, int new_x, int new_y);
int		handle_input(int key, t_game *game);

//map_parser.c
int		count_lines(const char *filename);
t_map	*parse_map(const char *filename);
int		validate_map(t_map *map);

//validate.c
int		validate_file(const char *filename);
int		validate_map_and_load(t_map **map, const char *filename);

//pathfinding.c
int		is_map_solvable(t_map *map);
int		flood_fill(t_map *temp, int x, int y, int *exit_found);
char	**duplicate_map(char **original, int width, int height);
void	free_map_array(char **map, int height);

//utils.c
char	*ft_strdup(const char *s);

#endif