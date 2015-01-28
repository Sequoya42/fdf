/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tryone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 19:40:07 by rbaum             #+#    #+#             */
/*   Updated: 2015/01/27 20:25:58 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fdf.h"

void    tryone(t_coord ***coord, t_try *try)
{
    int i;
    int j;
    int k;
    int l;

    i = 0;
    k = 0;
    l = 0;
    j = 0;
	try->yi = (int *)malloc(sizeof(int) * (coord[i][j]->size_x * coord[i][j]->size_y));
	try->yf = (int *)malloc(sizeof(int) * (coord[i][j]->size_x * coord[i][j]->size_y));
    while (i < coord[i][j]->size_y - 1)
    {
        j = 0;
		try->xi = (int *)malloc(sizeof(int) * (coord[i][j]->size_x * coord[i][j]->size_y));
		try->xf = (int *)malloc(sizeof(int) * (coord[i][j]->size_x * coord[i][j]->size_y));
        while (j < coord[i][j]->size_x - 1)
        {
            try->xi[k] = coord[i][j]->x;// - coord[i][j]->y;

			try->xf[k] = coord[i][j + 1]->x;// - coord[i][j + 1]->y;
            j++;
            k++;
        }
			try->yi[k] = (coord[i][j]->y);// + coord[i][j]->x) /2;
			try->yf[k] = (coord[i + 1][j]->y);// + coord[i + 1][j]->x)/2;
        i++;
        l++;
    }
}

int		main(int ac, char **av)
{
	t_coord ***coord;
	t_all *all;
	t_try *try;
	int i;

	i = 0;
	all = malloc(sizeof(t_all));
	try = malloc(sizeof(t_try));
	all->av = av;
	coord = (t_coord ***)malloc(sizeof(t_coord**));
	coord = ft_get_coord(all);
	tryone(coord, try);

	while (try->xi[i])
	{
	ft_putnbrn(try->xi[i]);	
		i++;
	}
	return (0);
}

