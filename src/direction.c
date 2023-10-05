/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:17:51 by sean              #+#    #+#             */
/*   Updated: 2023/06/25 22:52:46 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	x_dir(int x_start, int x_end)
{
	if (x_start <= x_end)
		return (1);
	else
		return (-1);
}

int	y_dir(int y_start, int y_end)
{
	if (y_start <= y_end)
		return (1);
	else
		return (-1);
}
