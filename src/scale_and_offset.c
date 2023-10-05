/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_and_offset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:12:54 by sean              #+#    #+#             */
/*   Updated: 2023/06/27 11:12:56 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	scale_and_offset(t_draw *draw, t_map *map)
{
	draw->x0 -= map->width / 2;
	draw->y0 -= map->height / 2;
	draw->x1 -= map->width / 2;
	draw->y1 -= map->height / 2;
	map->scale = (float)(HEIGHT / 2) / map->height;
	draw->x0 *= map->scale;
	draw->y0 *= map->scale;
	draw->x1 *= map->scale;
	draw->y1 *= map->scale;
	make_iso(&draw->x0, &draw->y0, draw->z0);
	make_iso(&draw->x1, &draw->y1, draw->z1);
	if (draw->z0 || draw->z1 > 0)
		map->colour = 0xdb4d69;
	else
		map->colour = 0xFFFFFF;
	draw->x0 += WIDTH / 2;
	draw->y0 += HEIGHT / 2;
	draw->x1 += WIDTH / 2;
	draw->y1 += HEIGHT / 2;
	draw->x_diff = ft_abs(draw->x1 - draw->x0);
	draw->y_diff = ft_abs(draw->y1 - draw->y0);
	draw->error = draw->x_diff - draw->y_diff;
}
