/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:43:16 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/10 00:54:06 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_linked_list              *c_node_adjlist(int index)
{
    t_linked_list *q = (t_linked_list*)malloc(sizeof(t_linked_list));
    q->data = index;
    q->visited = false;
    q->path = false;
    q->step = 0;
    q->next = NULL;
    return(q);
}

static void                add_edge_adjlist(int index_src, int index_dest, t_params *x)
{
    t_linked_list *tmp;
    //// SRC ----> dest
    tmp = c_node_adjlist(index_dest);
    tmp->next = x->hash_table[index_src].head;
    x->hash_table[index_src].head = tmp;
    //// DEST ---> src
    tmp = c_node_adjlist(index_src);
    tmp->next = x->hash_table[index_dest].head;
    x->hash_table[index_dest].head = tmp;
}

static void              set_index_adjlist(char *line, t_params *x)
{
     char **str;
     int index_src;
     int index_dest;

     str = ft_strsplit(line, '-');
     index_src = hashe(str[0]) % N_ROOM_MAX;
     index_dest = hashe(str[1]) % N_ROOM_MAX; 
     ft_free_db_tab(str);
     add_edge_adjlist(index_src, index_dest, x);
}
static int                parse_edge_adjlist(char *line, t_params *x)
{   
    char **str;
    int i;

    i = 0;
    str = ft_strsplit(line, '-');
    if(str[2])
        error();
    if(strcmp(str[0], x->hash_table[hashe(str[0]) % N_ROOM_MAX].name) == 0)
        i++;
    if(strcmp(str[1], x->hash_table[hashe(str[1]) % N_ROOM_MAX].name) == 0)
        i++;
    ft_free_db_tab(str);
    if(i == 2)
        return(1);
    else
        error();
    return(0);
}

 void                ft_data_adjlist(t_params *x)
 {
    char *line;

    parse_edge_adjlist(x->tmp, x);
    set_index_adjlist(x->tmp, x);
    while(get_next_line(STDIN_FILENO, &line) > 0)
    {
  //       x->storefile[x->t++] = ft_strdup(line);
        if(ft_check_str(line, '#') != 1 && ft_check_str(line, 'L') != 1)
        {
             parse_edge_adjlist(line, x);
             set_index_adjlist(line, x);
        }
        ft_strdel(&line);
    }
    split_name_room(&x->start);
    split_name_room(&x->end);
     dispatch_bfs(x);
}