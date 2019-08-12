/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:26:24 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/11 23:07:24 by viduvern         ###   ########.fr       */
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
# define ACCESS_HASH(index, string)  x->hash_table[index].string
# define N_ROOM x->nbr_room;
typedef struct  s_queue
{
    int *queue;
    int front;
    int rear;

}               t_queue;


typedef struct s_linked_list
{
    bool        visited;
    bool        path;
    int          data;
    size_t       step;
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
    int         nbr_room;
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

void            check_queue(t_params *x, int step, t_queue *q, int adjvertex);
int             dequeue(t_queue* q);
t_queue         *create_queue(t_params *x);
void            insert_queue(t_queue *q, int value);
int             start_end_vertex(t_params *x);
int             is_empty(t_queue *q); 
void            refresh_visited(t_params *x);
void            free_queue(t_queue *q);
void            ft_get_path(t_params *x, int vertex, t_queue *q);
void            init_hash_struct(t_params *x, char *line);
int             dispatch_bfs(t_params *x);
void            print_list(t_params *x, char *room);
void		    ft_free_params(t_params *x);
void		    ft_free_list(t_params *x);
int             main(int ac, char **av);
int             check_nbr_ants(t_params *x);
void            error();
char            *ft_parse(t_params *x);
size_t			hashe(char *str);
void            define_flags(char *line, t_params *x);
int              parse_room(char *line);
void            ft_data_adjlist(t_params *x);
void            split_name_room(char **line);
char		    **ft_free_db_tab(char **av);
void            free_tab(t_params *x);
void            free_queue(t_queue *q);
 void           refresh_visited(t_params *x);
void            refresh_tab(t_queue *q, t_params *x);

#endif
