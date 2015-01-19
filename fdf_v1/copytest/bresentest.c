/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:50:13 by rbaum             #+#    #+#             */
/*   Updated: 2015/01/17 17:06:08 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
/*

//			if (coord[i][j]->x < coord[i][j + 1]->x)

			ft_putnbrendl(coord[i][j]->x);
			ft_putnbrendl(coord[i][j + 1]->x);

void ligne(int xi,int yi,int xf,int yf) {
  int dx,dy,i,xinc,yinc,cumul,x,y ;
  x = xi ;
  y = yi ;
  dx = xf - xi ;
  dy = yf - yi ;
  allume_pixel(x,y) ;
  if ( dx > dy ) {
    cumul = dx / 2 ;
    for ( i = 1 ; i <= dx ; i++ ) {
      x += xinc ;
      cumul += dy ;
      if ( cumul >= dx ) {
        cumul -= dx ;
        y += yinc ; }
      allume_pixel(x,y) ; } }

    else {
    cumul = dy / 2 ;
    for ( i = 1 ; i <= dy ; i++ ) {
      y += yinc ;
      cumul += dx ;
      if ( cumul >= dy ) {
        cumul -= dy ;
        x += xinc ; }
      allume_pixel(x,y) ; } }


			mlx_pixel_put(e->mlx, e->win ,x ,y , 0X006700);
}
*/
void		draw(t_env *e, t_coord ***coord)
{
	int i;
//	int j;
	int x; 
	int y;
	int dx;
	int dy;
	int cumul;
	
	i = 0;
//	j = 0;
	x = 0;
	y = 0;
	dx = coord[y][x + 1]->x - coord[y][x]->x;
	dy = coord[y + 1][x]->y - coord[y][x]->y;
	mlx_pixel_put(e->mlx, e->win ,x ,y , 0X006700);
	if (dx > dy)
	{
		cumul = dx/2;
		i = 1;
		while (i <= dx)
		{
			x+= 1;
			cumul +=dy;
			if (cumul >= dx)
			{
				cumul -=dx;
				y += 1;
			}
			mlx_pixel_put(e->mlx, e->win ,coord[y][x]->x ,coord[y][x]->y , 0X006700);
			i++;
		}
	}
	else
	{
		cumul = dy / 2;
		i = 1;
		while (i <= dy)
		{
			y+= 1;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				x+= 1;
			}
			mlx_pixel_put(e->mlx, e->win ,coord[y][x]->x ,coord[y][x]->y , 0X006700);
		}
	}
/*	coord = coord;
	while (i < (**coord)->size_y)
	{
		j = 10;
		while (j < (**coord)->size_x)
		{
			mlx_pixel_put(e->mlx, e->win ,j ,i , 0X006700);
			j++;
		}
		i +=1;
		}*/
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
//	t_env	*e;
	t_coord	***coord;

	if (ac == 1)
		exit(0);
//	e = (t_env *)malloc(sizeof(t_env));
	all = (t_all *)malloc(sizeof(t_all));
	all->av = av;
	coord = ft_get_coord(all);
	coord = coord;
  int i = 0;
  int j = 0;
	while (i < (**coord)->size_y)
	{
		j = 0;
		while (j < (**coord)->size_x)
		{
			ft_putstr("valeur de y ");
			ft_putnbrn(coord[i][j]->y);
			ft_putstr("  valeur de x");
			ft_putnbrn(coord[i][j]->x);
			ft_putstr("  valeur de z ");
			ft_putnbrendl(coord[i][j]->z);
			j++;
		}
		i++;
	}
//	ft_mlx(e);
//	draw(e, coord);
//	sleep(3);
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
