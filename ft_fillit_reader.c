/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit_reader.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:33:59 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/19 18:31:27 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_valid_tet(char const *buff, int *i)
{
	int j;
	int d;

	j = 0;
	d = 0;
	while (d < SIZE)
	{
		if ((*i != 0 && buff[*i - 1] != LINE) && ('#' == buff[*i - 1]))
			j++;
		if ((buff[*i + 1] != LINE) && ('#' == buff[*i + 1]))
			j++;
		if (*i > 4 && ('#' == buff[*i - 5]))
			j++;
		if (*i < 14 && ('#' == buff[*i + 5]))
			j++;
		d++;
		i++;
	}
	if (j == 6 || j == 8)
		return (0);
	return (1);
}

static int		ft_valid_map(char *buff)
{
	int i[SIZE];
	int sharp_pos[SIZE];
	int j;

	ft_bzero(i, SIZE * SIZE);
	ft_bzero(sharp_pos, SIZE * SIZE);
	j = 0;
	while ((i[3] != SIZE) && buff[j])
	{
		if (buff[j] == '#' || buff[j] == '.')
		{
			if (buff[j] == '#' && i[0] <= SIZE)
				sharp_pos[i[0]++] = j;
			if (buff[j] == '.')
				i[1]++;
		}
		if (buff[j++] == LINE)
			i[3]++;
		else
			i[2]++;
	}
	if (i[0] == SIZE && i[1] == (SIZE * SIZE - SIZE) &&\
		i[2] == (SIZE * SIZE) && i[3] == SIZE)
		return (ft_valid_tet(buff, &sharp_pos[0]));
	return (1);
}

char			**ft_fillit_reader(int fd)
{
	char	**buff;
	int		i;

	if (!(buff = (char**)malloc(sizeof(char*) * (MAX_TET * TET_SIZE))))
		return (NULL);
	i = 0;
	while (i <= MAX_TET)
	{
		if (!(buff[i] = ft_strnew(TET_SIZE)))
			return (NULL);
		if (!(read(fd, buff[i], TET_SIZE)))
			return (buff);
		if (ft_valid_map(buff[i]))
			return (NULL);
		i++;
		g_tetcount = i;
	}
	return (NULL);
}
