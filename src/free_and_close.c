/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:03:25 by dev               #+#    #+#             */
/*   Updated: 2025/03/26 17:16:45 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void free_map(t_map *map)
{
    int i = 0;
    while (map->grid[i])
        free(map->grid[i++]);
    free(map->grid);
    free(map);
}

void free_textures(t_game *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
}

void close_game(t_game *game)
{
    free_textures(game);
    free_map(game->map);
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    free(game);
}
