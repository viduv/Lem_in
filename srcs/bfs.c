/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 12:50:29 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/11 03:51:00 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
void                ft_get_path(t_params *x, int vertex, t_queue *q)
{
    t_linked_list *s;
    size_t step = 0;
    int next_vertex = 0;
     step = ACCESS_HASH(vertex, head)->step;
    ft_putendl(ACCESS_HASH(vertex, name));
    while(step > 0)
    {
        s = ACCESS_HASH(vertex, head);
        ACCESS_HASH(vertex, head)->path = true;
        while(s != NULL)
         {
            next_vertex = s->data;
            if(ACCESS_HASH(next_vertex, head)->step == (step - 1))
            {
                    ft_putendl(ACCESS_HASH(vertex, name));
                vertex = next_vertex;
                break;
            }
            s = s->next;
         }
         step = ACCESS_HASH(vertex, head)->step;
    }
     refresh_visited(x);
     refresh_tab(q,x);
    // free_queue(q);
}

void            dispatch_bfs(t_params *x)
{
    t_queue *q;
    t_linked_list *l;
    int vertex = 0;
    int adjvertex = 0;
    size_t step = 0;

    q = create_queue(x);
    vertex = start_end_vertex(x);
    insert_queue(q, vertex);
    while(!is_empty(q))
    {
        if((vertex = dequeue(q)) == 0)
                break;
        l = ACCESS_HASH(vertex, head);
        step = ACCESS_HASH(vertex, head)->step;
        while(l != NULL)
         {
            if((hashe(x->end) % N_ROOM_MAX) == l->data)
              {
                ft_get_path(x, vertex, q);
                dispatch_bfs(x);
              }
            adjvertex = l->data;
            if(ACCESS_HASH(adjvertex, head)->visited == false && ACCESS_HASH(adjvertex, head)->path == false)
                check_queue(x, step, q, adjvertex);
            l = l->next;
        }
    }
}