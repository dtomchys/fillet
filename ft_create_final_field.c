/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_final_field.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:46:24 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/21 13:46:26 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_final_field(int size)
{
	int		i;
	char	**field;

	i = -1;
	if (!(field = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (++i < size)
	{
		field[i] = (char*)malloc(sizeof(char) * size + 1);
		field[i] = ft_memset(field[i], '.', size);
		field[i][size] = '\0';
	}
	field[size] = NULL;
	return (field);
}
