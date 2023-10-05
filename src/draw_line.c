/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 07:50:46 by shenders          #+#    #+#             */
/*   Updated: 2023/06/27 13:57:14 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_line(t_point *p0, t_point *p1, t_map *map)
{
	int		e2;
	t_draw	draw;

	draw = draw_init(p0, p1);
	scale_and_offset(&draw, map);
	while (draw.x0 != draw.x1 || draw.y0 != draw.y1)
	{
		if (check_bound(map, draw.x0, draw.y0))
			mlx_put_pixel(map->img, draw.x0, draw.y0, map->colour);
		e2 = draw.error * 2;
		if (e2 > -draw.y_diff)
		{
			draw.error -= draw.y_diff;
			draw.x0 += x_dir(draw.x0, draw.x1);
		}
		if (e2 < draw.x_diff)
		{
			draw.error += draw.x_diff;
			draw.y0 += y_dir(draw.y0, draw.y1);
		}
	}
}

		// if (draw.x0 == draw.x1 && draw.y0 == draw.y1)
		// {
		// 	if (check_bound(map, draw.x0, draw.y0))
		// 		mlx_put_pixel(map->img, draw.x0, draw.y0, map->colour);
		// 	break ;
		// }