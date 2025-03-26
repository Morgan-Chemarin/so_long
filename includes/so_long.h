/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:30:02 by dev               #+#    #+#             */
/*   Updated: 2025/03/26 16:53:52 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <mlx.h>
#include "../get-next-line/get_next_line.h"
#include "../ft_printf/ft_printf.h"

# define TILE_SIZE 64

typedef struct s_map
{
    char    **grid;
    int     width;
    int     height;
    int     player_x;
    int     player_y;
    int     collectibles;
}   t_map;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    void    *wall;
    void    *floor;
    void    *player;
    void    *collectible;
    void    *exit;
    int     moves;
    t_map   *map;
}   t_game;


t_map   *parse_map(const char *filename);
int     validate_map(t_map *map);
void    free_map(t_map *map);

int     init_game(t_game *game, t_map *map);
void    render_map(t_game *game);
void    close_game(t_game *game);

int     count_lines(const char *filename);

int handle_input(int key, t_game *game);

#endif