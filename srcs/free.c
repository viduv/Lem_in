/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 21:05:31 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/07 18:58:11 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		**ft_free_db_tab(char **av)
{
	int i;

	i = 0;
	if (!av)
		return (NULL);
	while (av[i] && av[i] != NULL)
		ft_strdel(&av[i++]);
	free(av);
	av = NULL;
	return (av);
}
void		ft_free_params(t_params *x)
{
	 ft_strdel(&x->start);
    ft_strdel(&x->end);
     ft_strdel(&x->tmp);
//     //ft_free_db_tab(x.storefile);
}
void		ft_free_list(t_params *x)
{

	int i = 0;
	t_linked_list *t;
	t_linked_list *y;

	while(i < N_ROOM_MAX)
	{
		 if(x->hash_table[i].name != NULL)
			ft_strdel(&x->hash_table[i].name);
		 if(x->hash_table[i].head != NULL)
		{
			t = x->hash_table[i].head;
			y = x->hash_table[i].head;
			while(t != NULL)
			{
				y = t->next;
				free(t);
				t = y;
			}
		}
		i++;
	}
}