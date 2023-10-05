/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:54:32 by shenders          #+#    #+#             */
/*   Updated: 2023/06/27 00:01:23 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{	
	t_map	*map;
	int		fd;

	if (argc != 2)
		error();
	fd = file_check(argv[1]);
	if (!fd)
		error();
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
	{	
		close(fd);
		error();
	}
	parse_map(map, argv[1]);
	mlx_start(map);
	clear_array(map, map->points);
	free(map);
	close(fd);
	return (0);
}
