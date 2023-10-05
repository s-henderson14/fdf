/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:19:37 by sean              #+#    #+#             */
/*   Updated: 2023/06/27 12:50:14 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <unistd.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}		t_point;

typedef struct s_map
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			width;
	int			height;
	t_point		**points;
	int			scale;
	int			colour;
}			t_map;

typedef struct s_draw
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	z0;
	int	z1;
	int	error;
	int	x_diff;
	int	y_diff;
}		t_draw;	

int		find_height(char *map);

int		find_width(char *map);

int		x_dir(int x_start, int x_end);

int		y_dir(int y_start, int y_end);

int		ft_abs(int x);

int		file_check(char *filename);

void	mlx_start(t_map *map);

void	parse_map(t_map *map, char *file);

void	save_point(t_map *map, int y, char *row);

void	draw_line(t_point *p0, t_point *p1, t_map *map);

void	make_iso(int *x, int *y, int z);

void	render_map(t_map *map);

void	error(void);

void	esc_key_hook(void *param);

t_draw	draw_init(t_point *p0, t_point *p1);

void	clean_split(char **arr);

void	clear_array(t_map *map, t_point **points);

void	clear_array1(t_point **points);

void	clean_error(t_map *map, t_point **arr);

void	mlx_map_error(t_map *map);

void	scale_and_offset(t_draw *draw, t_map *map);

int		check_bound(t_map *map, int x0, int y0);

#endif
