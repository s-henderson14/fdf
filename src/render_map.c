/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_map.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 14:50:06 by shenders      #+#    #+#                 */
/*   Updated: 2023/06/01 18:51:35 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	render_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				draw_line(&map->points[y][x], &map->points[y][x + 1], map);
			if (y < map->height - 1)
				draw_line(&map->points[y][x], &map->points[y + 1][x], map);
			x++;
		}
		y++;
	}
}
