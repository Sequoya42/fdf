/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 11:29:56 by rbaum             #+#    #+#             */
/*   Updated: 2015/02/05 19:09:30 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_get_tab(t_all *all)
{
	int		fd;
	int		i;
	char	*line;

	all->y = 0;
	i = 0;
	if ((fd = open(all->av[1], O_RDONLY)) < 0)
	{
		ft_putendl("Cannot open Map");
		exit(0);
	}
	while (get_next_line(fd, &line))
		all->y++;
	close(fd);
	fd = open(all->av[1], O_RDONLY);
	if ((all->tab = (char **)malloc(sizeof(char *) * (all->y + 1))) == NULL)
		exit (0);
	while (get_next_line(fd, &line))
	{
		if (line[0] != '\0')
			all->tab[i++] = line;
		else
			all->y--;
	}
	close(fd);
}

t_coord		*ft_new_coord(int x, int y, int z, int size_x)
{
	t_coord *coord;

	if ((coord = (t_coord *)malloc(sizeof(t_coord))) == NULL)
		return (NULL);
	coord->size_x = (size_x);
	coord->z = z;
	coord->x = x;
	coord->y = y;
	return (coord);
}

void		getch(int i, int j, t_all *all, t_coord ***coord)
{
	while (++j < all->x)
	{
		if (all->tmp[j] != '\0' && all->tmp[j][0] != '\n')
		{
			coord[i][j] = ft_new_coord(j, i, ft_atoi(all->tmp[j]), all->x);
			coord[i][j]->size_y = (all->y);
		}
	}
	free(all->tmp);
}

t_coord		***ft_get_coord(t_all *all)
{
	int		i;
	int		j;
	t_coord	***coord;

	i = 0;
	ft_get_tab(all);
	if ((coord = (t_coord ***)malloc(sizeof(t_coord **) * all->y + 1)) == NULL)
		return (NULL);
	while (i < all->y)
	{
		all->tmp = ft_strsplit(all->tab[i], ' ');
		all->x = 0;
		while (all->tmp[all->x] != '\0')
			all->x++;
		j = -1;
		if ((coord[i] = (t_coord **)malloc(sizeof(t_coord*) *
(all->x + 1))) == NULL)
			return (NULL);
		getch(i, j, all, coord);
		i++;
	}
	all->tmp = NULL;
	return (coord);
}
