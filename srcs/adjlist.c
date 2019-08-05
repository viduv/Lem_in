/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:43:16 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/03 13:40:47 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
// t_adjency             *ft_create_adjlist(int nbr, t_params *x)
// {
//     t_adjency *v = (t_adjency*)malloc(sizeof(t_adjency));
//     v->nb_room = x->nbr_room;
//     v->storefile = x->storefile;
//     return(v);
// }
t_node                *ft_add_data_adjlist(char *data)
{
    t_node *q =  malloc(sizeof(t_node));
    q->data = data;
    q->next = NULL;
    return(q);
}

void                ft_add_edge(char *src, char *dst, t_params *x)
{
    t_node *q =  ft_add_data_adjlist(dst);
    q->next = STR[hash(src) % N_ROOM_MAX];
    STR[hash(src) % N_ROOM_MAX] = q;
}

 void                ft_data_adjlist(t_params *x)
 {
    char *line;

    while(get_next_line(STDIN_FILENO, &line) > 0)
    {
         x->storefile[x->t++] = ft_strdup(line);
        if(ft_check_str(line, '#') != 1 && ft_check_str(line, 'L') != 1)
        {
             parse_edge(line, x);
        }
        ft_strdel(&line);
    }
    // free_tab(x);
}