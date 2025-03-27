/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:59:40 by dev               #+#    #+#             */
/*   Updated: 2025/03/27 15:31:46 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: Impossible to open %s\n", filename);
		return (0);
	}
	close(fd);
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
		ft_printf("Error: The map is invalid\n");
		return (0);
	}
	if (!is_map_solvable(*map))
	{
		free_map(*map);
		ft_printf("Error: The map is not solvable\n");
		return (0);
	}
	return (1);
}
