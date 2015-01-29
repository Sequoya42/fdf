/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oldy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 15:02:11 by rbaum             #+#    #+#             */
/*   Updated: 2015/01/23 18:02:44 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void draw_x(t_env *e, t_coord ***coord)
{
	int		i;
	int		j;
	t_inc	*inc;
	int cumul;
	

	inc = (t_inc *)malloc(sizeof(t_inc));
	i = 0;
	j = 0;
	inc->xi = coord[i][j]->x + 300;
	inc->xf = coord[i][j + 1]->x+ 300;
	inc->yi = coord[i][j]->y + 300;
	inc->yf = coord[i + 1][j]->y + 300;
	inc->dx = abs(inc->xf - inc->xi);
	inc->dy = abs(inc->yi - inc->yf);
	inc->xinc = (inc->dx < 0) ? -1 : 1;
	inc->yinc = (inc->dy < 0) ? -1 : 1;
/**********************************************/
	if (inc->dx > inc->dy)
	{
		cumul = inc->dx / 2;
		i = 0;
		while (++i <= inc->dx)
		{
			inc->xi += inc->xinc;
			cumul += inc->dy;
			if (cumul >= inc->dx)
			{
				cumul -= inc->dx;
				mlx_pixel_put(e->mlx, e->win, inc->xi + INC, inc->yi + INC, 0X006700);
			}
		}
	}
	else
	{
		cumul = inc->dy / 2;
		i = 1;
		while (i <= inc->dy)
		{
			inc->yi += inc->yinc;
			cumul += inc->dx;
			if (cumul >= inc->dy)
			{
				cumul -= inc->dy;
				inc->xi += inc->xinc;
			}
				mlx_pixel_put(e->mlx, e->win, inc->xi + INC, inc->yi + INC, 0X006700);
			i++;
		}
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

