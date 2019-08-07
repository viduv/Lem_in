/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:26:24 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/06 02:22:24 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "stdbool.h"
# include "sys/types.h"
# include "sys/stat.h"
# include "fcntl.h"
# include "ctype.h"

# define N_ROOM_MAX 100000
# define FNV_OFFSET_32 2166136261
# define FNV_PRIME_32 16777619
//# define STR      (x->hash_table[N_ROOM_MAX])

typedef struct s_linked_list
{
    bool        visited;
    int          data;
    struct s_linked_list   *next;
}               t_linked_list;


typedef struct              s_structure
{
    char        *name;
    t_linked_list *head;
}                           t_structure;

typedef struct               s_params
{
    size_t      nbr_ants;
    size_t      nbr_room;
    size_t      t;
    int         symb;
    int         error;
    t_structure      hash_table[N_ROOM_MAX];
    char        *name;
    char        *storefile[N_ROOM_MAX];  
    char        *tmp;
    char        *start;
    char        *end;
}                           t_params;


// typedef  struct                s_node
// {
//     bool        pass;
//     struct node *next;
// }                               t_node;

// typedef struct                  s_lst
// {
//     struct node *head;
// }                               t_lst;


int             main(int ac, char **av);
int             check_nbr_ants(t_params *x);
void            error();
char            *ft_parse(t_params *x);
size_t			hashe(char *str);
void            define_flags(char *line, t_params *x);
int              parse_room(char *line);
int             parse_edge(char *line, t_params *x);
void            ft_data_adjlist(t_params *x);
// void            ft_add_edge(char *src, char *dst, t_lst *x);
void            allocspace(char **line);
char		    **ft_free_db_tab(char **av);
void            free_tab(t_params *x);

#endif
