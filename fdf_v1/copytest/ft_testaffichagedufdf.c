/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testaffichagedufdf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 16:11:26 by rbaum             #+#    #+#             */
/*   Updated: 2015/01/15 16:11:27 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_fdf.h"

void	draw(t_env *e)
{
	int		x;
	int		y;

	y = 100;
	while (y < 200)
	{
		x = 100;
		while (x < 200)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, 0X006700);
			x++;
		}
		y++;
	}
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	ft_putstr("valeur de x :");
	ft_putnbr(x);
	ft_putchar('\n');
	ft_putstr("valeur de y :");
	ft_putnbr(y);
	ft_putchar('\n');
	return (0);
}

int		expose_hook(t_env *e)
{
	draw(e);
	return (0);
}


int		main(int ac, char **av)
{
	t_env	*e;
	int		x;
	int		y;

	y = 100;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 420, 420, "forty_two");
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
