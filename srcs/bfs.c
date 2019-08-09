/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 12:50:29 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/09 02:39:21 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int             start_end_vertex(t_params *x)
{
    int start_vertex;
    split_name_room(&x->start);
    split_name_room(&x->end);
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
    while(q->queue[i++] && i < x->nbr_room)
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

    if(is_empty(q))
    {
        printf("Queue is empty");
        item = -1;
    }
    else if(q->queue[q->front] == hashe(x->end) % N_ROOM_MAX)
        item = 0;
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
    int step;

    q = create_queue(x);
    vertex = start_end_vertex(x);
    insert_queue(q, vertex);
    while(!is_empty(q))
    {
        vertex = dequeue(q, x);
        if(vertex == 0)
        {
            ft_putendl("but");
            break;
        }
        l = ACCESS_HASH(vertex, head);
        step = ACCESS_HASH(vertex, head)->step;
        while(l != NULL)
        {
            adjvertex = l->data;
            if(ACCESS_HASH(adjvertex, head)->path == true)
                    ft_putendl("coucou les copains");
            else if(ACCESS_HASH(adjvertex, head)->visited == false)
             {
                ACCESS_HASH(adjvertex, head)->visited = true;
                ACCESS_HASH(adjvertex, head)->step += 1;
             }
            insert_queue(q, adjvertex);
            l = l->next;
        }
    }
}