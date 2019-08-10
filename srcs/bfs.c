/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 12:50:29 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/10 01:17:22 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int             start_end_vertex(t_params *x)
{
    int start_vertex;
    start_vertex = (hashe(x->start) % N_ROOM_MAX);
    x->hash_table[start_vertex].head->visited = true;
    return(start_vertex);
}

static t_queue         *create_queue(t_params *x)
{
    t_queue *q;
    int i;

    i = -1;
    q = (t_queue*)malloc(sizeof(t_queue));
    q->queue = (int*)malloc(sizeof(int) * x->nbr_room);
   while(i++ < x->nbr_room)
        q->queue[i] = 0;
    q->front = -1;
    q->rear = -1;
    ft_putendl("antoine tu as tord avec un d par contre");
    return(q);
}

int     is_empty(t_queue *q) 
{
    if(q->rear == -1) 
        return 1;
    else 
        return 0;
}

static void insert_queue(t_queue *q, int value)
{
    if(q->front == -1)
            q->front = 0;
     q->rear++;
     q->queue[q->rear] = value;
}

int dequeue(t_queue* q, t_params *x)
{
    int item;

   if(q->queue[q->front] == hashe(x->end) % N_ROOM_MAX)
       item = 5;
//    else if(q->queue[q->front + 1] == 0)
//        item = 0;
    else
    {
        item = q->queue[q->front];
        q->front++;
        if(q->front > q->rear)
            q->front = q->rear = -1;
    }
    return item;
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
        vertex = dequeue(q, x);
        l = ACCESS_HASH(vertex, head);
        step = ACCESS_HASH(vertex, head)->step;
        while(l != NULL)
        {
            if((hashe(x->end) % N_ROOM_MAX) == l->data)
              {
                  // BACKTRACK;
                  vertex = hashe(x->start) % N_ROOM_MAX;
                ft_putnbr(ACCESS_HASH(vertex, head)->step);
                ft_get_path(x, vertex);
               // ft_putendl("la");
                    break;
              }
            adjvertex = l->data;
            if(ACCESS_HASH(adjvertex, head)->visited == false && \
            ACCESS_HASH(adjvertex, head)->path == false)
             {
                ACCESS_HASH(adjvertex, head)->visited = true;
               ACCESS_HASH(adjvertex, head)->step = (step + 1);
                insert_queue(q, adjvertex);
             }
            l = l->next;
        }
    }
}