/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 12:50:29 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/16 04:04:51 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list_path              *c_node_path(int *path, int step)
{
    t_list_path *tmp = (t_list_path*)malloc(sizeof(t_list_path));
    tmp->step = step;
    tmp->path = path;
    tmp->ants = 0;
    tmp->next = NULL;
    return(tmp);
}

void                ft_store_path(int step, int *path, t_list_path **first)
{
    t_list_path *new;
    t_list_path *tmp;
    tmp = (*first);
    new = c_node_path(path, step);
    if((*first) == NULL)
        (*first) = new;
    else
    {
         while(tmp->next != NULL)
                tmp = tmp->next;
        tmp->next = new;
    }
}

void                ft_get_path(t_params *x, int vertex, t_queue *q, t_list_path **first)
{
   t_linked_list *s;
   size_t step;
   int next_vertex;
   int i = -1;
   int t = 1;
   int save_step;

   int *path = (int*)malloc(sizeof(int) * x->nbr_room); 
   next_vertex = 0;
   step = ACCESS_HASH(vertex, head)->step;
   save_step = step;
    while(i++ < x->nbr_room - 1)
        path[i] = 0;
    path[0] = hashe(x->end) % N_ROOM_MAX;
    ft_putendl(ACCESS_HASH(hashe(x->end) % N_ROOM_MAX, name));
    while(step > 0)
    {
        s = ACCESS_HASH(vertex, head);
        ACCESS_HASH(vertex, head)->path = true;
        while(s != NULL)
         {
            next_vertex = s->data;
            if(ACCESS_HASH(next_vertex, head)->step == (step - 1))
            {
                 path[t] = vertex;
                t++;
                vertex = next_vertex;
                break;
            }
            s = s->next;
         }
         step = ACCESS_HASH(vertex, head)->step;
    }
     refresh_visited(x);
     free_queue(q);
     ft_store_path(save_step, path, first);
}

int             recursive_bfs(t_params *x, t_linked_list *l, t_queue *q, int adjvertex, int step, int vertex, t_list_path **first)
{
            if((hashe(x->end) % N_ROOM_MAX) == l->data)
              {
                ft_get_path(x, vertex, q, first);
                dispatch_bfs(x, first);
                return(1);
              }
            adjvertex = l->data;
            if(ACCESS_HASH(adjvertex, head)->visited == false && ACCESS_HASH(adjvertex, head)->path == false)
                check_queue(x, step, q, adjvertex);
        return(0);
}

int           dispatch_bfs(t_params *x, t_list_path **first)
{
    t_queue *q;
    t_linked_list *l;
    int vertex;
    int adjvertex;
    size_t step; 
    
    step = 0;
    adjvertex = 0;
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
             if(recursive_bfs(x, l , q, adjvertex, step, vertex, first) == 1)
                return(1);
            l = l->next;
        }
    }
     free_queue(q);
    return(0);
}