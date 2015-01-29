/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   previouslefdf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 18:17:19 by rbaum             #+#    #+#             */
/*   Updated: 2015/01/27 17:22:11 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
//segfault grande map. reli epas bien les points en z
// le fichier affichemap.c fais nimp mais segfault pas
void	draw_x(t_env *e, t_coord ***coord)
{
	int		i;
	int		j;
	t_inc	*inc;

	int		y;
	int		a;
	int		b;

	i = 0;
	j = 0;
	inc = (t_inc *)malloc(sizeof(t_inc));
	while (inc->yi - STARTY < ((coord[i][j]->size_y - 1) * INC))
	{
		j = 0;
		inc->xf = 0;
		inc->yi = STARTY + coord[i][j]->y;
		if (inc->yf - STARTY != ((coord[i][j]->size_y - 1) * INC))
			inc->yf = STARTY + coord[i + 1][j]->y;
		while (inc->xf - STARTX < (coord[i][j]->size_x - 1) * INC)
		{
			inc->xi = STARTX + coord[i][j]->x;
			inc->xf = STARTX + coord[i][j + 1]->x;
			a = (inc->yf - inc->yi)/(inc->xf - inc->xi);
			b = (inc->yi - (a * inc->xi));
			y = y;
			while (inc->xi++ < inc->xf)
			{
			y = (a * inc->xi) + b;
				mlx_pixel_put(e->mlx, e->win, (inc->xi - inc->yi) + INC,
							  ((inc->yi + inc->xi)/2) + INC,
							  coord[i][j]->z == 0 ? 0XFF0000 : 0X55FF55);
			}
			j++;
		}
		if (i < (coord[i][j]->size_y - 1))
			i++;
	}
}

void draw_y(t_env *e, t_coord ***coord)
{
	int		i;
	int		j;
	t_inc	*inc;
	int		y;
	int		a;
	int		b;
	inc = (t_inc *)malloc(sizeof(t_inc));
	inc->xi = 0;
	inc->xf = 0;
	inc->yi = 0;
	inc->yf = 0;
	i = 0;
	j = 0;
	inc->xf = 30000;
	while (inc->xi - STARTX < (coord[i][j]->size_x - 1) * INC)
	{
		i = 0;
		inc->yf = 0;
		inc->xi = STARTX + coord[i][j]->x;
		if (inc->xf < (coord[i][j]->size_x -1) * INC)
			inc->xf = STARTX +  coord[i][j + 1]->x;
		while (inc->yf - STARTY < ((coord[i][j]->size_y - 1) * INC))
		{
			inc->yi = STARTY + coord[i][j]->y;
			inc->yf = STARTY +  coord[i + 1][j]->y;
			a = (inc->yf - inc->yi)/(inc->xf - inc->xi);
			b = (inc->yi - (a * inc->xi));
			y = y;
			while (inc->yi < inc->yf)
			{
				y = (a * inc->xi) + b;
				mlx_pixel_put(e->mlx, e->win, (inc->xi - inc->yi) + INC, 
							  ((inc->yi + inc->xi)/2 ) + INC + coord[i][j]->z,
							  coord[i][j]->z == 0 ? 0XFF0000 : 0X55FF55);
				if (coord[i][j]->z != 0)
				{
					ft_putnbrn(inc->xi);
					ft_putnbrendl(inc->yi);
				}
				inc->yi++;
			}
			i++;
		}
		if (j < (coord[i][j]->size_x - 1))
			j++;
	}
}


void	draw(t_env *e, t_coord ***coord)
{
	draw_x(e, coord);
	draw_y(e, coord);
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
	coord = (t_coord ***)malloc(sizeof(t_coord**));
	all->av = av;
	e = e;
	coord = ft_get_coord(all);
	ft_mlx(e, coord);
//	sleep(5);
	return (0);
}

