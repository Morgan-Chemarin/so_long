/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:00:55 by dev               #+#    #+#             */
/*   Updated: 2025/03/27 16:51:55 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#define KEY_W 122
#define KEY_A 113
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307

int	can_move(t_game *game, int new_x, int new_y)
{
	return (game->map->grid[new_y][new_x] != '1');
}

static void	update_coords(int key, int *x, int *y)
{
	if (key == KEY_W)
		(*y)--;
	else if (key == KEY_S)
		(*y)++;
	else if (key == KEY_A)
		(*x)--;
	else if (key == KEY_D)
		(*x)++;
}

static int	process_tile(t_game *game, int new_x, int new_y)
{
	if (game->map->grid[new_y][new_x] == 'C')
	{
		game->map->collectibles--;
		ft_printf("Collectible picked up! %d remaining\n",
			game->map->collectibles);
	}
	if (game->map->grid[new_y][new_x] == 'E')
	{
		if (game->map->collectibles > 0)
		{
			ft_printf("There are still %d collectibles left!\n",
				game->map->collectibles);
			return (0);
		}
		ft_printf("🎉 Victory ! 🎉\n");
		close_game(game);
		exit(0);
	}
	return (1);
}

static void	move_player(t_game *game, int new_x, int new_y)
{
	game->map->grid[game->map->player_y][game->map->player_x] = '0';
	game->map->grid[new_y][new_x] = 'P';
	game->map->player_x = new_x;
	game->map->player_y = new_y;
	game->moves++;
	ft_printf("Number of moves: %d\n", game->moves);
	render_map(game);
}

int	handle_input(int key, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->map->player_x;
	new_y = game->map->player_y;
	if (key == KEY_ESC)
	{
		close_game(game);
		exit(0);
	}
	update_coords(key, &new_x, &new_y);
	if (!process_tile(game, new_x, new_y))
		return (0);
	if (can_move(game, new_x, new_y))
		move_player(game, new_x, new_y);
	return (0);
}
