/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:33:11 by rbaum             #+#    #+#             */
/*   Updated: 2015/01/19 19:14:15 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include <fcntl.h>
#include "libft/libft.h"

# define INC 5


typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*content; 
}					t_env;

typedef struct		s_all
{
	char			**av;
	char			**tab;
	int				y;
}					t_all;

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	int				size_x;
	int				size_y;
}					t_coord;


void		ft_get_tab(t_all *all);
void		ft_get_good_tab(t_all *all);
t_coord		*ft_new_coord(int x, int y, int z, int size_x, int size_y);
t_coord		***ft_get_coord(t_all *all);




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
