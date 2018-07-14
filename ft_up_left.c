/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:46:47 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/21 13:46:49 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_up_left(t_tet *head)
{
	int x;
	int y;
	int i;

	while (head)
	{
		x = 3;
		y = 3;
		i = -1;
		while (++i < SIZE)
		{
			if (head->x[i] < x)
				x = head->x[i];
			if (head->y[i] < y)
				y = head->y[i];
			i++;
		}
		i = -1;
		while (++i < SIZE)
		{
			head->x[i] = head->x[i] - x;
			head->y[i] = head->y[i] - y;
		}
		head = head->next;
	}
}
