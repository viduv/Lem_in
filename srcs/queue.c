/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 03:10:06 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/11 03:33:24 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void              check_queue(t_params *x, int step, t_queue *q, int adjvertex)
{
     ACCESS_HASH(adjvertex, head)->visited = true;
     ACCESS_HASH(adjvertex, head)->step = (step + 1);
     insert_queue(q, adjvertex);
}
t_queue           *create_queue(t_params *x)
{
    t_queue *q;
    int i;

    q = (t_queue*)malloc(sizeof(t_queue));
    i = -1;
    q->queue = (int*)malloc(sizeof(int) * x->nbr_room);
   while(i++ < x->nbr_room - 1)
        q->queue[i] = 0;
    q->front = -1;
    q->rear = -1;
    ft_putendl("antoine tu as tord avec un d par contre");
    return(q);
}

void             insert_queue(t_queue *q, int value)
{
    if(q->front == -1)
            q->front = 0;
     q->rear++;
     q->queue[q->rear] = value;
}

int dequeue(t_queue* q)
{
    int item;

   if(q->queue[q->front + 1] == 0 && q->front != 0)
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