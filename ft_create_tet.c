/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:00:37 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/20 14:08:26 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			ft_set_size(t_tet *tet)
{
	int i;
	int j;

	tet->height = 0;
	tet->width = 0;
	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
			if (tet->x[j++] == i)
			{
				tet->width++;
				break ;
			}
		j = 0;
		while (j < SIZE)
			if (tet->y[j++] == i)
			{
				tet->height++;
				break ;
			}
		i++;
	}
}

static t_tet		*ft_make_tet(int **a, t_tet *new)
{
	int		i;
	t_tet	*new_a;

	new_a = new;
	i = 0;
	while (i++ < a[0][0])
		new = new->next;
	i = -1;
	while (++i < SIZE)
	{
		new->x[i] = a[1][i];
		new->y[i] = a[2][i];
	}
	ft_set_size(new);
	return (new_a);
}

t_tet				*ft_create_tet(char ***map, t_tet *head, int **i_x_y)
{
	while (i_x_y[0][0] < g_tetcount)
	{
		i_x_y[0][3] = 0;
		i_x_y[0][1] = 0;
		while (i_x_y[0][1] < SIZE)
		{
			i_x_y[0][2] = 0;
			while (i_x_y[0][2] < SIZE)
			{
				if (map[i_x_y[0][0]][i_x_y[0][1]][i_x_y[0][2]]\
					== '#')
				{
					i_x_y[1][i_x_y[0][3]] = i_x_y[0][2];
					i_x_y[2][i_x_y[0][3]++] = i_x_y[0][1];
				}
				i_x_y[0][2]++;
			}
			i_x_y[0][1]++;
		}
		head = ft_make_tet(i_x_y, head);
		i_x_y[0][0]++;
	}
	return (head);
}
