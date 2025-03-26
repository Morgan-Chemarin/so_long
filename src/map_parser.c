/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:00:50 by dev               #+#    #+#             */
/*   Updated: 2025/03/26 17:25:15 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int count_lines(const char *filename)
{
    int fd, count = 0;
    char *line;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (-1);

    while ((line = get_next_line(fd)))
    {
        free(line);
        count++;
    }
    close(fd);
    return (count);
}

t_map *parse_map(const char *filename)
{
    int fd, i = 0;
    char *line;
    t_map *map = malloc(sizeof(t_map));

    if (!map)
        return (NULL);
    map->collectibles = 0;
    map->height = count_lines(filename);
    map->grid = malloc(sizeof(char *) * (map->height + 1));
    if (!map->grid)
        return (free(map), NULL);

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (free(map->grid), free(map), NULL);

    while ((line = get_next_line(fd)))
    {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';

        map->grid[i++] = line;
        if (i == 1)
            map->width = strlen(line);
    }
    map->grid[i] = NULL;
    close(fd);
    return (map);
}

int validate_map(t_map *map)
{
    int x, y, player_count = 0, exit_count = 0;

    for (y = 0; y < map->height; y++)
    {
        if ((int)strlen(map->grid[y]) != map->width)
            return (ft_printf("Erreur : La carte n'est pas rectangulaire\n"), 0);

        for (x = 0; x < map->width; x++)
        {
            char c = map->grid[y][x];
            if ((y == 0 || y == map->height - 1 || x == 0 || x == map->width - 1) && c != '1')
                return (ft_printf("Erreur : La carte n'est pas fermée\n"), 0);
            if (c == 'P')
            {
                player_count++;
                map->player_x = x;
                map->player_y = y;
            }
            else if (c == 'E')
                exit_count++;
            else if (c == 'C')
                map->collectibles++;
            else if (c != '0' && c != '1')
                return (ft_printf("Erreur : Caractère invalide '%c'\n", c), 0);
        }
    }
    if (player_count != 1)
        return (ft_printf("Erreur : Il doit y avoir exactement 1 joueur\n"), 0);
    if (exit_count != 1)
        return (ft_printf("Erreur : Il doit y avoir exactement 1 sortie\n"), 0);
    if (map->collectibles < 1)
        return (ft_printf("Erreur : Il doit y avoir au moins 1 collectible\n"), 0);

    return (1);
}

