/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:59:40 by dev               #+#    #+#             */
/*   Updated: 2025/03/31 15:33:22 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_file(const char *filename)
{
	int	fd;
	int	len;

	if (!filename)
		return (0);
	len = 0;
	while (filename[len])
		len++;
	if (len < 4 || ft_strcmp(filename + len - 4, ".ber") != 0)
	{
		ft_printf("Error\nThe file must have a .ber extension\n");
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nImpossible to open %s\n", filename);
		return (0);
	}
	close(fd);
	return (1);
}

int	check_map_size(void *mlx, t_map *map)
{
	int	win_height;
	int	win_width;

	mlx_get_screen_size(mlx, &win_width, &win_height);
	if (map->width * TILE_SIZE > win_width ||
		map->height * TILE_SIZE > win_height)
	{
		ft_printf("Error\nMap size exceeds screen dimensions.\n");
		return (0);
	}
	return (1);
}

int	validate_map_and_load(t_map **map, const char *filename)
{
	if (!validate_file(filename))
		return (0);
	*map = parse_map(filename);
	if (!(*map) || !validate_map(*map))
	{
		free_map(*map);
		return (0);
	}
	if (!is_map_solvable(*map))
	{
		free_map(*map);
		ft_printf("Error\nThe map is not solvable\n");
		return (0);
	}
	return (1);
}
