/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 00:22:56 by rbaum             #+#    #+#             */
/*   Updated: 2015/02/05 20:07:55 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	get_real_coord(t_env *e)
{
	e->xa = e->inc->x1 - e->inc->y1 + OFF;
	e->xb = e->inc->x2 - e->inc->y1 + OFF;
	e->xc = e->inc->x1 - e->inc->y2 + OFF;
	e->ya = -(e->inc->z) + (e->inc->x1 + e->inc->y1) / 2 + YOFF;
	e->yb = -(e->inc->z2) + (e->inc->x2 + e->inc->y1) / 2 + YOFF;
	e->yc = -(e->inc->z3) + (e->inc->x1 + e->inc->y2) / 2 + YOFF;
}

int		fdf_draw_line_t1(t_env *e)
{
	int dx;
	int dy;
	int color;

	get_real_coord(e);
	color = e->inc->color;
	dx = (e->xb - e->xa);
	dy = (e->yb - e->ya);
	if (abs(dx) > abs(dy))
		while (dx += (dx < 0) - (dx > 0))
			mlx_pixel_put(e->mlx, e->win, e->xa + dx,
e->ya + dx * (e->yb - e->ya) / (e->xb - e->xa), color);
	else
		while (dy += (dy < 0) - (dy > 0))
			mlx_pixel_put(e->mlx,
e->win, e->xa + dy * (e->xb - e->xa) / (e->yb - e->ya),
e->ya + dy, color);
	return (0);
}

int		fdf_draw_line_t2(t_env *e)
{
	int dx;
	int dy;
	int color;

	get_real_coord(e);
	color = e->inc->color;
	dx = (e->xc - e->xa);
	dy = (e->yc - e->ya);
	if (abs(dx) > abs(dy))
	{
		while (dx += (dx < 0) - (dx > 0))
			mlx_pixel_put(e->mlx, e->win, e->xa + dx,
e->ya + dx * (e->yc - e->ya) / (e->xc - e->xa), color);
	}
	else
	{
		while (dy += (dy < 0) - (dy > 0))
			mlx_pixel_put(e->mlx,
e->win, e->xa + dy * (e->xc - e->xa) / (e->yc - e->ya),
e->ya + dy, color);
	}
	return (0);
}

void	ft_put_pixel(t_env *e, int i, int j)
{
	e = e;
	i = i;
	j = j;
	ft_calc_pixel(e, i, j);
	if (e->coord[i][j]->z != 0)
	{
		e->inc->color = e->coord[i][j]->z > 0 ? 0X800080 : 0XA09966;
		fdf_draw_line_t1(e);
		fdf_draw_line_t2(e);
	}
	else
	{
		e->inc->color = 0X048B9A;
		fdf_draw_line_t1(e);
		fdf_draw_line_t2(e);
	}
}
