/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:33:11 by rbaum             #+#    #+#             */
/*   Updated: 2015/01/30 20:06:00 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include <fcntl.h>
#include "libft/libft.h"

# define STARTX (WIDTH /2 )
# define STARTY (0)
# define INC 25
# define CONST 0.7
# define HEIGHT 1600
# define WIDTH 1200
# define ANGLE 45 * M_PI / 180

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	int				size_x;
	int				size_y;
}					t_coord;



typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*content;
	t_coord			***coord;
}					t_env;

typedef struct		s_inc
{
	int		xi;
	int		xf;
	int		yi;
	int		yf;
	int		dx;
	int		dy;
	int		xinc;
	int		yinc;
	int		err;
}					t_inc;

typedef struct		s_try
{
	int *xi;
	int *xf;
	int *yi;
	int *yf;
}					t_try;

typedef struct		s_all
{
	char			**av;
	char			**tab;
	int				y;
}					t_all;

void		ft_get_tab(t_all *all);
void		ft_get_good_tab(t_all *all);
t_coord		*ft_new_coord(int x, int y, int z, int size_x, int size_y);
t_coord		***ft_get_coord(t_all *all);
void		initial_inc(t_inc *inc);
void		pixel_put(int xi, int yi, t_env *e, int i, int j);
void		draw_x(t_env *e);
void		draw_y(t_env *e);
int			draw(t_env *e);




/*
** Commentaires et choses a faire **

open
◦ read
◦ write
8Projet d’Infographie fdf
◦ close
◦ malloc
◦ free
◦ perror
◦ strerror
◦ exit
◦ toutes les fonctions de la lib math (-lm et man 3 math)
◦ toutes les fonctions de la minilibX bien sûr

************man****************

 mlx_new_window
 mlx_pixel_put
 mlx_new_image
 mlx_loop

 ***********MAKE***************

gcc ft_fdf.c -L/usr/x11/lib -lmlx -lXext -lX11



 */
