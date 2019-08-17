/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 19:33:52 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/16 23:28:38 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list_path		*c_node_path(int *path, int step)
{
	t_list_path *tmp;

	tmp = (t_list_path*)malloc(sizeof(t_list_path));
	tmp->step = step;
	tmp->path = path;
	tmp->ants = 0;
	tmp->next = NULL;
	return (tmp);
}

void			ft_store_path(int step, int *path, t_list_path **first)
{
	t_list_path *new;
	t_list_path *tmp;

	tmp = (*first);
	new = c_node_path(path, step);
	if ((*first) == NULL)
		(*first) = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void			continue_path(t_params *x, t_queue *q, t_list_path **first, \
				int *path)
{
	refresh_visited(x);
	free_queue(q);
	ft_store_path(x->save_step, path, first);
}

int				*set_tab_path(int *path, t_params *x)
{
	int i;

	i = -1;
	path = (int*)malloc(sizeof(int) * x->nbr_room);
	while (i++ < x->nbr_room - 1)
		path[i] = 0;
	path[0] = hashe(x->end) % N_ROOM_MAX;
	return (path);
}

void			put_in_path(int **path, int *t, int *vertex, int next_vertex)
{
	(*path)[(*t)] = (*vertex);
	(*t)++;
	(*vertex) = next_vertex;
}
