/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   previouslefdf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 18:17:19 by rbaum             #+#    #+#             */
/*   Updated: 2015/01/27 21:35:00 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"


void	pixel_put(t_env *e, int i, int j, t_inc *inc)
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
			while (inc->xi++  < inc->xf)
				pixel_put(e, i, j, inc);
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
			inc->xf = STARTX +  e->coord[i][j + 1]->x;
		while (inc->yf - STARTY < ((e->coord[i][j]->size_y - 1) * INC))
		{
			inc->yi = STARTY + e->coord[i][j]->y;
			inc->yf = STARTY + e->coord[i + 1][j]->y;
			while (inc->yi < inc->yf)
			{
				pixel_put(e, i, j, inc);
				inc->yi++;
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
