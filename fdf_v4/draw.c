/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 19:16:35 by rbaum             #+#    #+#             */
/*   Updated: 2015/01/30 20:04:25 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	initial_inc(t_inc *inc)
{
	inc->xi = 0;
	inc->xf = 0;
	inc->yi = 0;
	inc->yf = 0;
}
void	pixel_put(int xi,int  yi, t_env *e, int i, int j)
{
	if (e->coord[i][j]->z == 0)
		mlx_pixel_put(e->mlx, e->win, (xi - yi), (xi + yi)/2, 0X00FF0000);
	else
		mlx_pixel_put(e->mlx, e->win, (xi - yi), (xi + yi)/2, 0X808080FF);
}
void	draw_x(t_env *e)
{
	int	 i;
	int	 j;
	t_inc   *inc;

	i = 0;
	j = 0;
	inc = malloc(sizeof(t_inc));
	initial_inc(inc);
	while ((inc->yi - STARTY) < ((e->coord[i][j]->size_y - 1) * INC))
	{
		j = 0;
		inc->xf = 0;
		inc->yi = STARTY + e->coord[i][j]->y;
		if (inc->yf - STARTY != ((e->coord[i][j]->size_y - 1) * INC))
			inc->yf = STARTY + e->coord[i + 1][j]->y;
		while (inc->xf - STARTX < (e->coord[i][j]->size_x - 1) * INC)
		{
			inc->xi = STARTX + e->coord[i][j]->x;
			inc->xf = STARTX + e->coord[i][j + 1]->x;
			while (inc->xi++ < inc->xf)
				pixel_put(inc->xi, inc->yi, e, i, j);
			j++;
		}
		if (i < (e->coord[i][j]->size_y - 1))
			i++;
	}
}

void	draw_y(t_env *e)
{
	int i;
	int j;
	t_inc *inc;

	i = 0;
	j = 0;
	inc = (t_inc *)malloc(sizeof(t_inc));
	initial_inc(inc);
	while ((inc->xi - STARTX) < ((e->coord[i][j]->size_x -1) * INC))
	{
		i = 0;
		inc->yf = 0;
		inc->xi = STARTX + e->coord[i][j]->x;
		if (inc->xf - STARTX < ((e->coord[i][j]->size_x -1) * INC))
			inc->xf = STARTX + e->coord[i][j + 1]->x;
		while (inc->yf < (e->coord[i][j]->size_y - 1) * INC)
		{
			inc->yi = e->coord[i][j]->y;
			inc->yf = e->coord[i + 1][j]->y;
			while (inc->yi++ < inc->yf)
				pixel_put(inc->xi, inc->yi, e, i, j);
			i++;
		}
		if (j < e->coord[i][j]->size_x -1)
			j++;
	}
}

int	 draw(t_env *e)
{
	draw_x(e);
	draw_y(e);
	return (0);
}
