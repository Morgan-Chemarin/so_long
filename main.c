/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:55:31 by dev               #+#    #+#             */
/*   Updated: 2025/03/31 15:14:39 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	if (argc != 2)
		return (ft_printf("Error\n./so_long <map.ber>\n"), 1);
	if (!validate_map_and_load(&map, argv[1]))
		return (1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	game->moves = 0;
	if (!init_game(game, map))
	{
		free(game);
		return (1);
	}
	render_map(game);
	mlx_loop(game->mlx);
	close_game(game);
	return (0);
}
