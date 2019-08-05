/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:26:24 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/03 14:53:56 by viduvern         ###   ########.fr       */
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
# define STR           (x->init_tab)

typedef struct               s_params
{
    size_t      nbr_ants;
    size_t      nbr_room;
    size_t      t;
    int         symb;
    int         error;
    char        *init_tab[N_ROOM_MAX];
    char        *storefile[N_ROOM_MAX];  
    char        *tmp;
    char        *start;
    char        *end;
}                           t_params;

typedef     struct lem_in {

    char *str;
};

//  typedef struct              s_adjency
//  {
//      int   nb_room;
//      t_params   *storefile[N_ROOM_MAX];
//      bool       visited;
//      char        *tmp;

//  }                           t_adjency;

typedef     struct          s_node
{
    char   *data;
    struct t_node *next;
}                            t_node;

//  typedef    struct          t_head
//  {
//      char    *line;
//      t_node  **adjlist;
//  }                            s_head;
 

int             main(int ac, char **av);
int             check_nbr_ants(t_params *x);
void            error();
char            *ft_parse(t_params *x);
size_t			hash(char *str);
void            define_flags(char *line, t_params *x);
int             parse_room(char *line);
int             parse_edge(char *line, t_params *x);
void            ft_data_adjlist(t_params *x);
t_node          *ft_add_data_adjlist(char *data);
void            ft_add_edge(char *src, char *dst, t_params *x);
void            allocspace(char **line);
char		    **ft_free_db_tab(char **av);
void            free_tab(t_params *x);

#endif