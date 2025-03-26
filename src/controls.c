/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:00:55 by dev               #+#    #+#             */
/*   Updated: 2025/03/26 17:00:00 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#define KEY_W 122
#define KEY_A 113
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307

int can_move(t_game *game, int new_x, int new_y)
{
    return (game->map->grid[new_y][new_x] != '1');
}

int handle_input(int key, t_game *game)
{
    int new_x = game->map->player_x;
    int new_y = game->map->player_y;

    if (key == KEY_W) 
        new_y--;
    else if (key == KEY_S) 
        new_y++;
    else if (key == KEY_A) 
        new_x--;
    else if (key == KEY_D) 
        new_x++;
    else if (key == KEY_ESC) 
    {
        close_game(game);
        exit(0);
    }

    // mettre dans un fichier separé "verification case actuelle"
    if (game->map->grid[new_y][new_x] == 'C')
    {
        game->map->collectibles--; 
        ft_printf("Collectible ramassé ! Il en reste %d\n", game->map->collectibles);
    }

    if (game->map->grid[new_y][new_x] == 'E' && game->map->collectibles > 0)
    {
        ft_printf("Il reste encore %d collectibles, récupérez-les avant de sortir !\n", game->map->collectibles);
        return (0); 
    }

    if (game->map->grid[new_y][new_x] == 'E' && game->map->collectibles == 0)
    {
        ft_printf("🎉 Victoire ! 🎉\n");
        close_game(game);
        exit(0);
    }

    if (can_move(game, new_x, new_y))
    {
        game->map->grid[game->map->player_y][game->map->player_x] = '0';
        game->map->grid[new_y][new_x] = 'P';

        game->map->player_x = new_x;
        game->map->player_y = new_y;

        game->moves++;
        ft_printf("Nb de mouvement : %d\n", game->moves);

        render_map(game);
    }

    return (0);
}
