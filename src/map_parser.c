/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:00:50 by dev               #+#    #+#             */
/*   Updated: 2025/03/31 15:14:57 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_lines(const char *filename)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static int	read_map_lines(int fd, t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (i < map->height && line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map->grid[i] = line;
		if (i == 0)
			map->width = ft_strlen(line);
		i++;
		line = get_next_line(fd);
	}
	map->grid[i] = NULL;
	return (i);
}

t_map	*parse_map(const char *filename)
{
	int		fd;
	t_map	*map;

	map = malloc(sizeof(t_map));
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
	read_map_lines(fd, map);
	close(fd);
	return (map);
}

static int	validate_row(t_map *map, int y, int *player_count, int *exit_count)
{
	int		x;
	char	c;

	x = 0;
	while (x < map->width)
	{
		c = map->grid[y][x];
		if ((y == 0 || y == map->height - 1 || x == 0 || \
		x == map->width - 1) && c != '1')
			return (ft_printf("Error\nThe map is not enclosed\n"), 0);
		if (c == 'P')
		{
			(*player_count)++;
			map->player_x = x;
			map->player_y = y;
		}
		else if (c == 'E')
			(*exit_count)++;
		else if (c == 'C')
			map->collectibles++;
		else if (c != '0' && c != '1')
			return (ft_printf("Error\nInvalid character '%c'\n", c), 0);
		x++;
	}
	return (1);
}

int	validate_map(t_map *map)
{
	int	y;
	int	player_count;
	int	exit_count;

	player_count = 0;
	exit_count = 0;
	y = 0;
	while (y < map->height)
	{
		if ((int)ft_strlen(map->grid[y]) != map->width)
			return (ft_printf("Error\nThe map is not rectangular\n"), 0);
		if (!validate_row(map, y, &player_count, &exit_count))
			return (0);
		y++;
	}
	if (player_count != 1)
		return (ft_printf("Error\nThere must be exactly 1 player\n"), 0);
	if (exit_count != 1)
		return (ft_printf("Error\nThere must be exactly 1 exit\n"), 0);
	if (map->collectibles < 1)
		return (ft_printf("Error\nThere must be exactly 1 collectible\n"), 0);
	return (1);
}
