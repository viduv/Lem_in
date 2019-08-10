/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 23:14:14 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/10 01:20:46 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void             ft_name_path(char *name)
{
    char *str;
     str = ft_strdup(name);
 //   ft_putendl(name);
}

void                ft_get_path(t_params *x, int vertex)
{
    t_linked_list *s;
    size_t step;
    int next_vertex;

    s = ACCESS_HASH(vertex, head);
    step = ACCESS_HASH(vertex, head)->step;
    ft_name_path(ACCESS_HASH(vertex, name)); 
    ACCESS_HASH(vertex, head)->path = true;
    while(s != NULL)
    {
        next_vertex = s->data;
        if(ACCESS_HASH(next_vertex, head)->step == (step - 1))
            ft_get_path(x, next_vertex);
        s = s->next;
    }
}