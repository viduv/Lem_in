/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dispatch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 19:40:50 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/16 23:31:55 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		reverse_path(t_list_path *first)
{
	t_list_path *tmp;

	tmp = first;
	while (tmp != NULL)
	{
		tmp->path = reverse_integer(tmp->path);
		tmp = tmp->next;
	}
}

int			path_ants_counts(t_list_path **tmp, size_t *nbr_ants)
{
	(*tmp)->ants++;
	(*nbr_ants)++;
	if ((*tmp)->next != NULL && \
			(*tmp)->ants + (*tmp)->step > (*tmp)->next->step)
	{
		(*tmp) = (*tmp)->next;
		return (1);
	}
	return (0);
}

void		path_ants_count(t_list_path *first, t_params *x)
{
	t_list_path		*tmp;

	while (x->count_ants < x->nbr_ants)
	{
		tmp = first;
		while (tmp != NULL && x->count_ants < x->nbr_ants)
			if (x->count_ants > 0)
			{
				if (path_ants_counts(&tmp, &x->count_ants) == 1)
					;
				else
					break ;
			}
			else
				while (x->count_ants < x->nbr_ants)
				{
					if (tmp->next && tmp->ants + tmp->step > tmp->next->step)
					{
						tmp = tmp->next;
						break ;
					}
					tmp->ants++;
					x->count_ants++;
				}
	}
}

int			*ft_index_zero(t_params *x)
{
	int *index;
	int i;

	i = 0;
	index = (int*)malloc(sizeof(int) * x->nbr_room);
	while (i < x->nbr_room)
	{
		index[i] = 0;
		i++;
	}
	return (index);
}

void		set_index(t_list_path *first, t_params *x)
{
	t_list_path *tmp;

	tmp = first;
	while (tmp != NULL)
	{
		tmp->index = ft_index_zero(x);
		tmp = tmp->next;
	}
}
