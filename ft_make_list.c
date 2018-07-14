/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:52:46 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/21 13:52:47 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet	*ft_make_list(int length)
{
	int		i;
	t_tet	*head;
	t_tet	*next;

	if (!(next = (t_tet*)malloc(sizeof(t_tet) + 1)))
		return (NULL);
	head = next;
	i = 1;
	while (i++ < length)
	{
		if (!(next->next = (t_tet*)malloc(sizeof(t_tet) + 1)))
			return (NULL);
		next = next->next;
	}
	next->next = NULL;
	return (head);
}
