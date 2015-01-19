/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdftest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:01:41 by rbaum             #+#    #+#             */
/*   Updated: 2015/01/18 15:39:03 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_fdf.h"

void		draw(t_env *e, t_coord ***coord)
{
	int i;
	int j;
	int yolo;
	int swag;


	i = 0;
	j = 0;
	
	i = 50;
	coord = coord;
	yolo = ((**coord)->size_y);
	swag = ((*coord[0])->size_x);
	while (i < yolo)
	{
		j = 50;
		
		while (j < swag)
		{
			mlx_pixel_put(e->mlx, e->win,i ,j , 0X006700);
			j += 1;
		}
		i +=INC;
		}
	i = 50;
	while (i < yolo)
	{
		j = 50;
		while (j < swag)
		{
			mlx_pixel_put(e->mlx, e->win,i ,j , 0X006700);
			j += INC;
		}
		i +=1;
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
	sleep(10);
	return (0);
}

/*



*/
