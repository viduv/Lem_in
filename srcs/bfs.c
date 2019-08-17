/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 12:50:29 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/16 23:26:56 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_get_path(t_params *x, int vertex, t_queue *q, t_list_path **first)
{
	t_linked_list	*s;
	size_t			step;

	x->t = 1;
	step = ACCESS_HASH(vertex, head)->step;
	x->save_step = step;
	x->path = set_tab_path(x->path, x);
	while (step > 0)
	{
		s = ACCESS_HASH(vertex, head);
		ACCESS_HASH(vertex, head)->path = true;
		while (s != NULL)
		{
			x->next_vertex = s->data;
			if (ACCESS_HASH(x->next_vertex, head)->step == (step - 1))
			{
				put_in_path(&x->path, &x->t, &vertex, x->next_vertex);
				break ;
			}
			s = s->next;
		}
		step = ACCESS_HASH(vertex, head)->step;
	}
	continue_path(x, q, first, x->path);
}

int		recursive_bfs(t_params *x, t_linked_list *l, t_queue *q, \
		t_list_path **first)
{
	if ((hashe(x->end) % N_ROOM_MAX) == l->data)
	{
		ft_get_path(x, x->vertex, q, first);
		dispatch_bfs(x, first);
		return (1);
	}
	x->adjvertex = l->data;
	if (ACCESS_HASH(x->adjvertex, head)->visited == false \
		&& ACCESS_HASH(x->adjvertex, head)->path == false)
		check_queue(x, x->step, q, x->adjvertex);
	return (0);
}

int		dispatch_bfs(t_params *x, t_list_path **first)
{
	t_queue			*q;
	t_linked_list	*l;

	q = create_queue(x);
	x->vertex = start_end_vertex(x);
	insert_queue(q, x->vertex);
	while (!is_empty(q))
	{
		if ((x->vertex = dequeue(q)) == 0)
			break ;
		l = ACCESS_HASH(x->vertex, head);
		x->step = ACCESS_HASH(x->vertex, head)->step;
		while (l != NULL)
		{
			if (recursive_bfs(x, l, q, first) == 1)
				return (1);
			l = l->next;
		}
	}
	free_queue(q);
	return (0);
}
