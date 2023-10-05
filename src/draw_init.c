/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:17:56 by sean              #+#    #+#             */
/*   Updated: 2023/06/26 11:04:46 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_draw	draw_init(t_point *p0, t_point *p1)
{
	t_draw	draw;

	draw.x0 = p0->x;
	draw.y0 = p0->y;
	draw.x1 = p1->x;
	draw.y1 = p1->y;
	draw.z0 = p0->z;
	draw.z1 = p1->z;
	draw.x_diff = ft_abs(draw.x1 - draw.x0);
	draw.y_diff = ft_abs(draw.y1 - draw.y0);
	draw.error = draw.x_diff - draw.y_diff;
	return (draw);
}
