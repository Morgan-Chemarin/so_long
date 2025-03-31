/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:00:45 by dev               #+#    #+#             */
/*   Updated: 2025/03/31 15:26:58 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*load_texture(void *mlx, char *path)
{
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(mlx, path, &w, &h);
	if (!img)
		ft_printf("Error\nCan't load %s\n", path);
	return (img);
}

int	init_game(t_game *game, t_map *map)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, map->width * TILE_SIZE,
			map->height * TILE_SIZE, "so_long");
	if (!game->win)
		return (0);
	game->map = map;
	game->wall = load_texture(game->mlx, "assets/wall.xpm");
	game->floor = load_texture(game->mlx, "assets/floor.xpm");
	game->player = load_texture(game->mlx, "assets/player.xpm");
	game->collectible = load_texture(game->mlx, "assets/collectible.xpm");
	game->exit = load_texture(game->mlx, "assets/exit.xpm");
	if (!game->wall || !game->floor || !game->player || \
	!game->collectible || !game->exit)
		return (ft_printf("Error\nProblem loading textures\n"), 0);
	mlx_hook(game->win, 2, 1L << 0, handle_input, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	return (1);
}

void	put_tile_image(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P' || \
	(x == game->map->player_x && y == game->map->player_y))
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collectible,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			tile = game->map->grid[y][x];
			if (game->map->grid[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor,
					x * TILE_SIZE, y * TILE_SIZE);
			put_tile_image(game, tile, x, y);
			x++;
		}
		y++;
	}
}
