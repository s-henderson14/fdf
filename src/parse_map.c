/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:58:19 by shenders          #+#    #+#             */
/*   Updated: 2023/06/28 11:45:37 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	find_height(char *map)
{
	int		fd;
	int		height;
	char	*row;

	fd = open(map, O_RDONLY);
	height = 0;
	row = get_next_line(fd, 0);
	if (!row)
	{	
		close (fd);
		return (-1);
	}
	while (row != NULL)
	{
		height++;
		free(row);
		row = get_next_line(fd, 0);
	}
	close(fd);
	return (height);
}

int	find_width(char *map)
{
	int		fd;
	int		width;
	int		i;
	char	*row;
	char	**args;

	fd = open (map, O_RDONLY);
	width = 0;
	i = 0;
	row = get_next_line(fd, 1);
	if (!row)
		return (close(fd), -1);
	args = ft_split(row, ' ');
	if (!args)
		return (close(fd), free(row), -1);
	while (args[i] && *args[i] != 10)
	{
		width++;
		i++;
	}
	free(row);
	clean_split(args);
	return (close(fd), width);
}

void	save_point(t_map *map, int y, char *row)
{
	char	**coordinate;
	int		x;

	coordinate = ft_split(row, ' ');
	if (!coordinate)
		clean_error(map, map->points);
	x = 0;
	while (x < map->width)
	{	
		map->points[y][x].x = x;
		map->points[y][x].y = y;
		map->points[y][x].z = ft_atoi(coordinate[x]);
		free(coordinate[x]);
		x++;
	}
	free(coordinate[x]);
	free(coordinate);
}

void	add_points(t_map *map, char *file)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(file, O_RDONLY, 0);
	if (!fd)
		clean_error(map, map->points);
	line = get_next_line(fd, 0);
	if (!line)
	{	
		close(fd);
		clean_error(map, map->points);
	}
	y = 0;
	while (y < map->height)
	{
		save_point(map, y, line);
		free(line);
		line = get_next_line(fd, 0);
		y++;
	}
	if (line)
		free(line);
	close(fd);
}

void	parse_map(t_map *map, char *file)
{
	int	i;

	map->height = find_height(file);
	map->width = find_width(file);
	map->points = ft_calloc(map->height, sizeof (t_point *));
	if (map->height == -1 || map->width == -1 || !map->points)
		clean_error(map, map->points);
	i = 0;
	while (i < map->height)
	{
		map->points[i] = ft_calloc((map->width), sizeof(t_point));
		if (!map->points[i])
			clean_error(map, map->points);
		i++;
	}
	add_points(map, file);
}
