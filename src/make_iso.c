/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_iso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:17:16 by sean              #+#    #+#             */
/*   Updated: 2023/06/27 11:05:04 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	make_iso(int *x, int *y, int z)
{
	double	angle;
	int		temp;

	angle = 0.55;
	temp = *x;
	*x = (int )(temp - *y) *cos(angle);
	*y = (int )(temp + *y) *sin(angle) - z;
}
