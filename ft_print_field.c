/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_field.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:57:55 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/21 13:57:56 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_sqrt(int num)
{
	int i;

	i = 0;
	while (i * i < num)
		i++;
	return (i);
}

static	void	ft_map_print(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i++]);
		ft_putstr("\n");
	}
}

void			ft_print_field(t_tet *head)
{
	int		size;
	char	**field;

	size = ft_sqrt(g_tetcount * SIZE);
	field = ft_create_final_field(size);
	ft_up_left(head);
	g_tetletter = -1;
	while (!(ft_put_field(field, head, size)))
	{
		g_tetletter = -1;
		ft_memdel((void**)field);
		field = ft_create_final_field(++size);
	}
	ft_map_print(field);
	ft_memdel((void**)field);
}
