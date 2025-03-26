/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:00:45 by dev               #+#    #+#             */
/*   Updated: 2025/03/26 17:04:52 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void *load_texture(void *mlx, char *path)
{
	int w;
	int h;
	void *img;

	img = mlx_xpm_file_to_image(mlx, path, &w, &h);
	if (!img)
		ft_printf("Erreur : Impossible de charger %s\n", path);
	return (img);
}

int init_game(t_game *game, t_map *map)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_printf("Erreur : MinilibX n'a pas pu être initialisé\n"), 0);
	game->win = mlx_new_window(game->mlx, map->width * TILE_SIZE, map->height * TILE_SIZE, "so_long");
	game->map = map;
	game->wall = load_texture(game->mlx, "assets/wall.xpm");
	game->floor = load_texture(game->mlx, "assets/floor.xpm");
	game->player = load_texture(game->mlx, "assets/player.xpm");
	game->collectible = load_texture(game->mlx, "assets/collectible.xpm");
	game->exit = load_texture(game->mlx, "assets/exit.xpm");
	if (!game->wall || !game->floor || !game->player || !game->collectible || !game->exit)
		return (ft_printf("Erreur : Problème de chargement des textures\n"), 0);
	mlx_hook(game->win, 2, 1L << 0, handle_input, game);
	return (1);
}

void render_map(t_game *game)
{
	int y = 0;
	while (y < game->map->height)
	{
		int x = 0;
		while (x < game->map->width)
		{
			char tile = game->map->grid[y][x];
			mlx_put_image_to_window(game->mlx, game->win, game->floor, x * TILE_SIZE, y * TILE_SIZE);
			if (tile == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'P' || (x == game->map->player_x && y == game->map->player_y))
				mlx_put_image_to_window(game->mlx, game->win, game->player, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collectible, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

