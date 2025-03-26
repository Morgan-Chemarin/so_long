/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:55:31 by dev               #+#    #+#             */
/*   Updated: 2025/03/26 17:48:11 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int main(int argc, char **argv)
{
	t_map *map;
	t_game *game;
	int		fd;

	if (argc != 2)
		return (ft_printf("Usage: ./so_long <map.ber>\n"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Erreur : Impossible d'ouvrir %s\n", argv[1]), 1);
	close(fd);
	map = parse_map(argv[1]);
	if (!map || !validate_map(map))
	{
		free_map(map);
		return (ft_printf("Erreur : La carte est invalide\n"), 1);
	}
	game = malloc(sizeof(t_game));
	if (!game)
		return (ft_printf("Erreur : Allocation mémoire échouée\n"), 1);
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
