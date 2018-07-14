/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:34:44 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/21 13:30:18 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# define SIZE		4
# define MAX_TET	26
# define TET_SIZE	21
# define LINE		'\n'

int					g_size;
int					g_tetcount;
int					g_tetletter;

typedef	struct		s_tet
{
	int				x[SIZE];
	int				y[SIZE];
	int				width;
	int				height;
	struct s_tet	*next;
}					t_tet;

char				**ft_fillit_reader(int fd);
t_tet				*ft_create_tet(char ***map, t_tet *head, int **i_x_y);
void				ft_up_left(t_tet *head);
char				**ft_create_final_field(int size);
int					ft_put_field(char **field, t_tet *head, int size);
t_tet				*ft_make_list(int length);
void				ft_print_field(t_tet *head);

#endif
