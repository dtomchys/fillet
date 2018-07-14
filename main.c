/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:31:14 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/21 13:38:19 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char			***ft_make_3d(char **map)
{
	int		i;
	char	***map_3d;

	i = 0;
	if (!(map_3d = (char***)malloc(sizeof(char**) * (g_tetcount + 1))))
		return (NULL);
	while (i <= g_tetcount)
	{
		map_3d[i] = ft_strsplit(map[i], '\n');
		i++;
	}
	return (map_3d);
}

static int			**ft_extra_f(void)
{
	int	j;
	int	**res;

	j = 0;
	if (!(res = (int**)malloc(sizeof(int*) * 3 + 1)))
		return (NULL);
	while (j < 3)
	{
		res[j] = (int*)malloc(sizeof(int) * 4);
		ft_bzero(res[j], SIZE * SIZE);
		j++;
	}
	return (res);
}

int					main(int argc, char **argv)
{
	int		fd;
	char	**map;
	t_tet	*head;

	if (argc != 2)
	{
		ft_putstr("usage : ");
		ft_putstr(argv[0]);
		ft_putstr(" [fillit_format]\n");
		exit(EXIT_FAILURE);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit(EXIT_FAILURE);
	if (!(map = ft_fillit_reader(fd)) || map[0][0] == '\0'\
		|| map[g_tetcount - 1][TET_SIZE - 1])
	{
		ft_putstr("error\n");
		exit(EXIT_FAILURE);
	}
	head = ft_create_tet(ft_make_3d(map), ft_make_list(g_tetcount),\
		ft_extra_f());
	ft_memdel((void**)map);
	ft_print_field(head);
	close(fd);
	return (0);
}
