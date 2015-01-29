/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testcoefficient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 18:03:14 by rbaum             #+#    #+#             */
/*   Updated: 2015/01/24 14:31:38 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_fdf.h"

void draw_x(t_env *e, t_coord ***coord)
{
	int		i;
	int		j;
	t_inc	*inc;
	int		x;
	int		y;
	int		a;
	int		b;

	
	inc = (t_inc *)malloc(sizeof(t_inc));
	i = 0;
	j = 0;
	inc->xi = 0;
	inc->yi = 0;
	while (inc->yi- 300 < (coord[i][j]->size_y * INC))
	{
		j = 0;
		inc->xf = 0;
		inc->yi = 300 + coord[i][j]->y;// + ((CONST / 2) * coord[i][j]->z) ;
		inc->yi = 300 + coord[i][j]->y;// + ((CONST / 2) * coord[i][j]->z) ;
		while (inc->xf - 300 < (coord[i][j]->size_x) * INC)
		{
			inc->xi = 300 +(coord[i][j]->x);// +( CONST * coord[i][j]->z));
			inc->xf = 300 + (coord[i][j + 1]->x);// + (CONST * coord[i][j + 1]->z));
			x = inc->xi;

			y = y;
			while (x++ < inc->xf)
			{
			a = (inc->yf - inc->yi)/(inc->xf - inc->xi);
			b = (inc->yi - (a * inc->xi));
			y = (a * x) + b;
				mlx_pixel_put(e->mlx, e->win, x + INC, y + INC, 0XFF0000);
				mlx_pixel_put(e->mlx, e->win, y + INC, x + INC, 0XFF6600);
			}
			j++;
		}
		if (i < coord[i][j]->size_y)
			i++;
	}
}

void	draw_y(t_env *e, t_coord ***coord)
{
	int i;
	int j;
	t_inc *inc;
	int x;
	int y;
	int a;
	int b;

	inc = (t_inc *)malloc(sizeof(t_inc));
	inc->xi = 0;
	j = 0;
	while (inc->xi - 300 < (coord[i][j]->size_x * INC))
	{
		i = 0;
		inc->yf = 0;
		inc->xi = 300 + (coord[i][j]->x + (CONST * coord[i][j]->z));
		inc->xf = 300 + (coord[i][j + 1]->x + (CONST * coord[i][j + 1]->z));
		while (inc->yf - 300 < (coord[i][j]->size_y * INC))
		{
			inc->yi = 300 + coord[i][j]->y + ((CONST / 2) * coord[i][j]->z) ;
			inc->yf = 300 + coord[i + 1][j]->y + ((CONST / 2) * coord[i + 1][j]->z) ;
			a = (inc->yf - inc->yi)/(inc->xf - inc->xi);
			b = (inc->yi - (a * inc->xi));
			x = inc->xi;
			while (inc->yi++ < inc->yf)
			{
				y = (a * x) + b;
				mlx_pixel_put(e->mlx, e->win, x + INC, y + INC, 0X006700);
				mlx_pixel_put(e->mlx, e->win, y + INC, x + INC, 0X006700);
			}
			i++;
		}
		if (j < coord[i][j]->size_x)
 			j++;
	}
}


void	draw(t_env *e, t_coord ***coord)
{
	draw_x(e, coord);
//	draw_y(e, coord);
}
/*
int expose_hook(t_env *e, t_coord ***coord)
{
draw(e, coord);
return (0);
}
*/
int key_hook(int keycode)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

void ft_mlx(t_env *e, t_coord ***coord)
{

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1400, 1600, "fdf");
	mlx_key_hook(e->win, key_hook, e);
	draw(e, coord);
// mlx_expose_hook(e->win, expose_hook, e);
mlx_loop(e->mlx);

}

int main(int ac, char **av)
{
	t_all *all;
	t_env *e;
	t_coord ***coord;

	if (ac == 1)
		exit(0);
	e = (t_env *)malloc(sizeof(t_env));
	all = (t_all *)malloc(sizeof(t_all));
	all->av = av;
	coord = ft_get_coord(all);
	coord = coord;
	ft_mlx(e, coord);
	
//	sleep(5);
	return (0);
}

