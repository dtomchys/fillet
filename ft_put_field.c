/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_field.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:36:51 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/21 13:36:54 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_checker(char **field, t_tet *head, int x, int y)
{
	int i;

	i = 0;
	g_tetletter++;
	while (i < SIZE)
	{
		if (((head->y[i] + y) >= g_size || (head->x[i] + x) >= g_size))
		{
			g_tetletter--;
			return (0);
		}
		if (field[y + head->y[i]][x + head->x[i]] != '.')
		{
			g_tetletter--;
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < SIZE)
	{
		field[y + head->y[i]][x + head->x[i]] = 'A' + g_tetletter;
		i++;
	}
	return (1);
}

static void		ft_get_back(char **field, t_tet *head, int x, int y)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		field[y + head->y[i]][x + head->x[i]] = '.';
		i++;
	}
}

int				ft_put_field(char **field, t_tet *head, int size)
{
	int i;
	int j;

	if (!head)
		return (1);
	g_size = size;
	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (ft_checker(field, head, i, j))
			{
				if (ft_put_field(field, head->next, size))
					return (1);
				g_tetletter--;
				ft_get_back(field, head, i, j);
			}
			i++;
		}
		j++;
	}
	return (0);
}
