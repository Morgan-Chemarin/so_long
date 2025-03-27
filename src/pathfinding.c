/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:08:53 by dev               #+#    #+#             */
/*   Updated: 2025/03/27 16:11:31 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map_array(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**duplicate_map(char **original, int width, int height)
{
	char	**copy;
	int		y;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	copy[height] = NULL;
	y = 0;
	while (y < height)
	{
		copy[y] = ft_strdup(original[y]);
		if (!copy[y])
		{
			free_map_array(copy, y);
			return (NULL);
		}
		y++;
	}
	return (copy);
}

int	flood_fill(t_map *temp, int x, int y, int *exit_found)
{
	if (x < 0 || x >= temp->width || y < 0 || y >= temp->height)
		return (0);
	if (temp->grid[y][x] == '1' || temp->grid[y][x] == 'V')
		return (0);
	if (temp->grid[y][x] == 'C')
		temp->collectibles--;
	if (temp->grid[y][x] == 'E')
		*exit_found = 1;
	temp->grid[y][x] = 'V';
	if (temp->collectibles == 0 && *exit_found)
		return (1);
	if (flood_fill(temp, x + 1, y, exit_found))
		return (1);
	if (flood_fill(temp, x - 1, y, exit_found))
		return (1);
	if (flood_fill(temp, x, y + 1, exit_found))
		return (1);
	if (flood_fill(temp, x, y - 1, exit_found))
		return (1);
	return (0);
}

int	is_map_solvable(t_map *map)
{
	t_map	temp;
	int		exit_found;
	int		result;

	exit_found = 0;
	temp.width = map->width;
	temp.height = map->height;
	temp.player_x = map->player_x;
	temp.player_y = map->player_y;
	temp.collectibles = map->collectibles;
	temp.grid = duplicate_map(map->grid, map->width, map->height);
	if (!temp.grid)
		return (0);
	result = flood_fill(&temp, temp.player_x, temp.player_y, &exit_found);
	free_map_array(temp.grid, temp.height);
	return (result);
}
