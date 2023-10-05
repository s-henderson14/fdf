/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:48:15 by sean              #+#    #+#             */
/*   Updated: 2023/06/26 23:18:10 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

#include "../include/fdf.h"

void	clean_error(t_map *map, t_point **arr)
{
	if (arr)
		clear_array(map, arr);
	if (map)
		free(map);
	exit(EXIT_FAILURE);
}

void	clear_array(t_map *map, t_point **points)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		if (points[y] != NULL)
			free(points[y]);
		y++;
	}
	free(points);
}

void	mlx_map_error(t_map *map)
{
	mlx_delete_image(map->mlx, map->img);
	clear_array(map, map->points);
	free(map);
	exit(EXIT_FAILURE);
}

void	clean_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// void	clear_array1(int **points)
// {
// 	int	i;

// 	i = 0;
// 	while (points[i])
// 	{
// 		if (points != NULL)
// 			free(points[i]);
// 		i++;
// 	}
// 	exit(EXIT_FAILURE);
// }
