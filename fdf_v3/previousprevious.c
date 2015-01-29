/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   previouslefdf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 18:17:19 by rbaum             #+#    #+#             */
/*   Updated: 2015/01/29 19:01:41 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void line(int x0, int y0, int x1, int y1, t_env *e) 
{

    int dx = abs(x1-x0);
	int sx = x0<x1 ? 1 : -1;
    int dy = abs(y1-y0);
    int sy = y0<y1 ? 1 : -1;
    int err = (dx>dy ? dx : -dy)/2;
    int e2;
    while (x0!=x1 && y0!=y1)
    {
		mlx_pixel_put(e->mlx, e->win, (x0 - y0) + INC,
					  (((y0 + x0)/2) + (INC/2)) ,  0X00FF00);
        e2 = err;
        if (e2 >-dx)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y0 += sy;
        }
	}
}

void line_2(int x0, int y0, int x1, int y1, t_env *e) 
{
    int dx = abs(x1-x0);
    int sx = x0<x1 ? 1 : -1;
    int dy = abs(y1-y0);
    int sy = y0<y1 ? 1 : -1;
    int err = dy/2;
    int e2;
    while (y0++ < y1)
    {
		mlx_pixel_put(e->mlx, e->win, (x0 - y0) + INC,
					  (((y0 + x0)/2) + (INC/2)) ,  0X00FF00);
//		mlx_pixel_put(e->mlx, e->win, (((y0 + x0)/2) + (INC/2)) , 
//					  (x0 - y0) + INC, 0X00FF00);
        e2 = err;
        if (e2 >-dx)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void	pixel_put_y(t_env *e, int i, int j, t_inc *inc)
{
	while (inc->yi < inc->yf)
	{
		if (e->coord[i][j]->z == 0)
		{
			mlx_pixel_put(e->mlx, e->win, (inc->xi - inc->yi) + INC,
						  (((inc->yi + inc->xi)/2) + INC),  0XFF0000);
		}
		else
		{
			mlx_pixel_put(e->mlx, e->win, (inc->xi - inc->yi) + INC,
						  (((inc->yi + inc->xi)/2) + INC), 0X00FF00);
		}
		inc->yi++;
	}
}

void	pixel_put_x(t_env *e, int i, int j, t_inc *inc)
{
	while (inc->xi++ < inc->xf)
	{
		if (e->coord[i][j]->z == 0)
		{
			mlx_pixel_put(e->mlx, e->win, (inc->xi - inc->yi) + INC,
						  (((inc->yi + inc->xi)/2) + INC),  0XFF0000);
		}
		else
		{
			mlx_pixel_put(e->mlx, e->win, (inc->xi - inc->yi) + INC,
						  (((inc->yi + inc->xi)/2) + INC), 0X00FF00);
		}
	}
}

void	draw_x(t_env *e)
{
	int		i;
	int		j;
	t_inc	*inc;

	i = 0;
	j = 0;
	inc = (t_inc *)malloc(sizeof(t_inc));
	while (inc->yi - STARTY < ((e->coord[i][j]->size_y - 1) * INC))
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
			if (e->coord[i][j]->z > 0)
				line(inc->xi, inc->yi, inc->xf, inc->yf, e);
			else
				pixel_put_x(e, i, j, inc);
			j++;
		}
		if (i < (e->coord[i][j]->size_y - 1))
			i++;
	}
}

void draw_y(t_env *e)
{
	int		i;
	int		j;
	t_inc	*inc;

	inc = (t_inc *)malloc(sizeof(t_inc));
	i = 0;
	j = 0;
	inc->xf = 30000;
	while (inc->xi - STARTX < (e->coord[i][j]->size_x - 1) * INC)
	{
		i = 0;
		inc->yf = 0;
		inc->xi = STARTX + e->coord[i][j]->x;
		if (inc->xf < (e->coord[i][j]->size_x -1) * INC)
			inc->xf = STARTX + e->coord[i][j + 1]->x;
		while (inc->yf - STARTY < ((e->coord[i][j]->size_y - 1) * INC))
		{
			inc->yi = STARTY + e->coord[i][j]->y;
			inc->yf = STARTY + e->coord[i + 1][j]->y;
			if (e->coord[i][j]->z > 0)
				line_2(inc->xi, inc->yi, inc->xf, inc->yf, e);
			else
			{
				pixel_put_y(e, i, j, inc);
				ft_putendl("yolo");
			}
			i++;
		}
		if (j < (e->coord[i][j]->size_x - 1))
			j++;
	}
}

int		draw(t_env *e)
{
	draw_x(e);
	draw_y(e);
	return (0);
}

int expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

int key_hook(int keycode)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

void ft_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1400, 1600, "fdf");
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
}

int main(int ac, char **av)
{
	t_all *all;
	t_env *e;
	if (ac == 1)
		exit(0);
	e = (t_env *)malloc(sizeof(t_env));
	all = (t_all *)malloc(sizeof(t_all));
	all->av = av;
	e->coord = ft_get_coord(all);
	ft_mlx(e);
	return (0);
}
