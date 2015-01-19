/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdftest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:01:41 by rbaum             #+#    #+#             */
/*   Updated: 2015/01/19 19:18:01 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_fdf.h"
/*
pour liso

x = x - y
y = (x + y) / 2 - z
----------

gere pas les map genre pylone.fdf ou pyramide
*/


void		draw(t_env *e, t_coord ***coord)
{
	int i;
	int j;
	int xi;
	int xf;
	int yi;
	int yf;

	i = 0;
	j = 0;
	xi = 0;
	yi = 0;
	while (yi < (coord[i][j]->size_y * INC))
	{
		j = 0;
		xf = 0;
		yi = coord[i][j]->y;
		while (xf < (coord[i][j]->size_x) * INC)
		{
			xi = coord[i][j]->x;
			xf = coord[i][j +1]->x;	
			while (xi++ < xf) 
				mlx_pixel_put(e->mlx, e->win, xi + INC, yi + INC, ((coord[i][j]->z <= 0) ? 0X006700 : 0XFF0000));
			j++;
		}
		if (i < coord[i][j]->size_y)
			i++;
	}

	xi = 0;
	j = 0;
	while (xi < (coord[i][j]->size_x * INC))
	{
		i = 0;
		yf = 0;
		xi = coord[i][j]->x;
		while (yf < (coord[i][j]->size_y * INC))
		{
			yi = coord[i][j]->y;
			yf = coord[i + 1][j]->y;
			while (yi++ < yf)
				mlx_pixel_put(e->mlx, e->win, xi + INC, yi + INC, ((coord[i][j]->z <= 0) ? 0X006700 : 0XFF0000));
			i++;
		}
		if (j < coord[i][j]->size_x)
			j++;
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
	e->win = mlx_new_window(e->mlx, 1200, 1400, "fdf");
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



*/
