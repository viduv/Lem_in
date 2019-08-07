/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:43:16 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/06 03:08:22 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void                       print_list(t_params *x, int index_src)
{
     t_linked_list *print = x->hash_table[index_src].head;
     int a = 0;

     while(print != NULL)
     {
           ft_putnbr(print->data);
           ft_putchar('\n');
          print = print->next;
          a++;
     }
     printf("**************%d\n*********", a);
}
t_linked_list              *c_node(int index_dest)
{
    t_linked_list *q = (t_linked_list*)malloc(sizeof(t_linked_list));
    q->data = index_dest;
    q->next = NULL;
    return(q);
}

void                add_edge(int index_src, int index_dest, t_params *x)
{
    t_linked_list *tmp = c_node(index_dest);
    tmp->next = x->hash_table[index_src].head;
    x->hash_table[index_src].head = tmp;
}

void              set_src(char *line, t_params *x)
{
     char **str;
     int index_src;
     int index_dest;

     str = ft_strsplit(line, '-');
     index_src = hashe(str[0]) % N_ROOM_MAX;
     index_dest = hashe(str[1]) % N_ROOM_MAX; 
     x->hash_table[index_src].head = NULL;
     ft_free_db_tab(str);
     add_edge(index_src, index_dest, x);
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
             set_src(line, x);
        }
        ft_strdel(&line);
        print_list(x, 31020);
    }
    // free_tab(x);
}