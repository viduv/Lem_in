/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_queue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 23:14:14 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/11 23:15:32 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void             ft_intdel(int **s)
{
    if(s != NULL)
    {
        free(*s);
        *s = NULL;
    }
}
int             start_end_vertex(t_params *x)
{
    int start_vertex;
    start_vertex = (hashe(x->start) % N_ROOM_MAX);
    x->hash_table[start_vertex].head->visited = true;
    return(start_vertex);
}

 void                refresh_visited(t_params *x)
    {
        int i;

        i = 0;
        while(i < N_ROOM_MAX)
            if(x->hash_table[i].head != NULL)
             {
                x->hash_table[i].head->visited = false;
                x->hash_table[i].head->step = 0;
                i++;
             }
             else
                i++;
    }
void                    free_queue(t_queue *q)
{
     ft_intdel(&q->queue);
     free(q);
}