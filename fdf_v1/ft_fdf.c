/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:50:13 by rbaum             #+#    #+#             */
/*   Updated: 2015/01/19 18:49:54 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		draw(t_env *e, t_coord ***coord)
{
	int dx;
	int dy;
	int err;
	int e2;
	int x0;
	int y0;
	int x1;
	int y1;
	int i = 0;
	int j = 0;

	x0 = coord[i][j]->x;
	x1 = coord[i][j + 1]->x;
	y0 = coord[i][j]->y;
	y1 = coord[i + 1][j]->y;
	dx = x1 - x0;
	dy = y1 - y0;
	err = (dx > dy ? dx : -dy)/2;
	while (1)
	{
		mlx_pixel_put(e->mlx, e->win ,x0 ,y0 , 0X006700);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = err;
		if (e2 >-dx) 
			err -= dy; x0 += 1; 
		if (e2 < dy) 
			err += dx; y0 += 1;
	}
}
/*
int			expose_hook(t_env *e)//, t_coord ***coord)
{
		draw(e);//, coord);
	return (0);
}
*/
int			key_hook(int keycode)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

void		ft_mlx(t_env *e)
{

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 800, 600, "fdf");
	mlx_key_hook(e->win, key_hook, e);
	
//	mlx_expose_hook(e->win, expose_hook, e);
//	mlx_loop(e->mlx);

}

int			main(int ac, char **av)
{
	t_all	*all;
	t_env	*e;
	t_coord	***coord;

	if (ac == 1)
		exit(0);
	e = (t_env *)malloc(sizeof(t_env));
	all = (t_all *)malloc(sizeof(t_all));
	all->av = av;
	coord = ft_get_coord(all);
	coord = coord;
	ft_mlx(e);
	draw(e, coord);
	sleep(5);
	return (0);
}

/*

	int i = 0;
	int j = 0;
	while (i < (**coord)->size_y)
	{
		j = 0;
		while (j < (*coord[i])->size_x)
			ft_putnbrn(coord[i][j++]->z);
		ft_putchar('\n');
		i++;
		}

*/
