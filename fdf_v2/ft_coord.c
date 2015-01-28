/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 11:29:56 by rbaum             #+#    #+#             */
/*   Updated: 2015/01/27 21:35:50 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void        ft_get_tab(t_all *all)
{
    int     fd;
    int     i;
    char    *line;

     all->y = 0;
    i = 0;
    fd = open(all->av[1], O_RDONLY);
    while (get_next_line(fd, &line))
        all->y++;
    close(fd);
    fd = open(all->av[1], O_RDONLY);
    all->tab = (char **)malloc(sizeof(char *) * (all->y + 1));
    while (get_next_line(fd, &line))
        all->tab[i++] = line;
    close(fd);
}

void        ft_get_good_tab(t_all *all)
{
    int i;
    int j;

    i = 0;
    ft_get_tab(all);
    while (all->tab[i])
    {
        j = 0;
        while (all->tab[i][j])
        {
            if ((all->tab[i][j] < 48 || all->tab[i][j] > 57) &&
                all->tab[i][j] != 43 && all->tab[i][j] != 45)
                all->tab[i][j] = ' ';
            j++;
        }
        i++;
    }
}
/*
x - y
(x +y ) / 2
 */
t_coord     *ft_new_coord(int x, int y, int z, int size_x, int size_y)
{
    t_coord *coord;

    coord = (t_coord *)malloc(sizeof(t_coord));
    if (coord == NULL)
        return (NULL);
    coord->z = z;
    coord->x = x * INC; //abs((x * INC) - (y * INC));//+ z;// * cos(ANGLE)) - (y * INC * sin(ANGLE));
    coord->y = (y * INC);// + z;// ((y * INC) + (x * INC)) / 2 ;// *sin(ANGLE)) + cos(y * INC * cos(ANGLE));

//FAIRE UN TRUC AvEC LE Z
    coord->size_x = (size_x);
    coord->size_y = (size_y);
    return (coord);
}

t_coord     ***ft_get_coord(t_all *all)
{
    int     i;
    int     j;
    char    **tmp;
    int     tmp_size;
    t_coord ***coord;

    i = 0;
    ft_get_good_tab(all);
    coord = (t_coord ***)malloc(sizeof(t_coord **) * all->y + 1);
    while (i < all->y)
    {
        tmp = ft_strsplit(all->tab[i], ' ');
        tmp_size = 0;
        while (tmp[tmp_size] != '\0')
            tmp_size++;
        coord[i] = (t_coord **)malloc(sizeof(t_coord*) * (tmp_size + 1));
        j = -1;
        while (++j < tmp_size)
            coord[i][j] = ft_new_coord(j, i, ft_atoi(tmp[j]), tmp_size, all->y);
        free(tmp);
        i++;
    }
    tmp = NULL;
    i = 0;
    return (coord);
}
