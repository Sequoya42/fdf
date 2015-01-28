#include "ft_fdf.h"

void draw(t_env *e, t_coord ***coord)
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
	while (yi - 300 < ((coord[i][j]->size_y -1) * INC))
	{
		j = 0;
		xf = 0;
		yi = coord[i][j]->y + 300;
		while (xf - 300 < (coord[i][j]->size_x -1) * INC)
		{
			xi = coord[i][j]->x + 300;
			xf = coord[i][j +1]->x + 300;
			while (xi++ < xf) 
				mlx_pixel_put(e->mlx, e->win, xi + INC, yi + INC, 0XFF0000);
			mlx_pixel_put(e->mlx, e->win, yi + INC, xi + INC, 0XFF0000);
			j++;
		}
		if (i < coord[i][j]->size_y -1)
			i++;
	}
/******************************************************************************/
	xi = 0;
	j = 0;
	while (xi - 300 < ((coord[i][j]->size_x -1) * INC))
	{
		i = 0;
		yf = 0;
		xi = coord[i][j]->x + 300;
		while (yf - 300 < ((coord[i][j]->size_y -1) * INC))
		{
			yi = coord[i][j]->y + 300;
			yf = coord[i + 1][j]->y + 300;
			while (yi++ < yf)
				mlx_pixel_put(e->mlx, e->win, xi + INC, yi + INC, ((coord[i][j]->z <= 0) ? 0X006700 : 0XFF0000));
			i++;
		}
		if (j < coord[i][j]->size_x -1)
			j++;
	}
}

/*
  intexpose_hook(t_env *e)//, t_coord ***coord)
{
draw(e);//, coord);
return (0);
}
*/
int key_hook(int keycode)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

void ft_mlx(t_env *e)
{

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1200, 1400, "fdf");
	mlx_key_hook(e->win, key_hook, e);
	
//mlx_expose_hook(e->win, expose_hook, e);
//mlx_loop(e->mlx);

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
	ft_mlx(e);
	draw(e, coord);
	sleep(5);
	return (0);
}
