/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:26:24 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/17 11:43:21 by viduvern         ###   ########.fr       */
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

typedef struct			s_list_path
{
	int					step;
	int					*path;
	int					ants;
	int					*index;
	struct s_list_path	*next;
}						t_list_path;

typedef struct			s_queue
{
	int					*queue;
	int					front;
	int					rear;
}						t_queue;

typedef struct			s_linked_list
{
	bool				visited;
	bool				path;
	int					data;
	size_t				step;
	struct s_linked_list*next;
}						t_linked_list;

typedef struct			s_structure
{
	char				*name;
	t_linked_list		*head;
}						t_structure;

typedef struct			s_params
{
	size_t				nbr_ants;
	size_t				count_ants;
	int					vertex;
	int					*path;
	int					adjvertex;
	size_t				step;
	int					nbr_room;
	int					t;
	size_t				next_vertex;
	int					s;
	int					error;
	t_structure			hash_table[N_ROOM_MAX];
	char				*name;
	char				*tmp;
	int					save_step;
	char				*start;
	char				*end;
}						t_params;

void					put_in_path(int **path, int *t, int *vertex, \
						int next_vertex);
int						*set_tab_path(int *path, t_params *x);
void					continue_path(t_params *x, t_queue *q, \
						t_list_path **first, int *path);
void					ft_store_path(int step, int *path, t_list_path **first);
t_list_path				*c_node_path(int *path, int step);
int						*reverse_integer(int *tab);
void					dispatch(t_params *x, t_list_path *first);
void					ft_free_path(t_list_path *head);
void					check_queue(t_params *x, int step, t_queue *q,\
						int adjvertex);
int						dequeue(t_queue *q);
t_queue					*create_queue(t_params *x);
void					insert_queue(t_queue *q, int value);
int						start_end_vertex(t_params *x);
int						is_empty(t_queue *q);
void					refresh_visited(t_params *x);
void					free_queue(t_queue *q);
void					ft_get_path(t_params *x, int vertex, t_queue *q, \
						t_list_path **first);
void					init_hash_struct(t_params *x, char *line);
int						dispatch_bfs(t_params *x, t_list_path **first);
void					print_list(t_params *x, char *room);
void					ft_free_params(t_params *x);
void					ft_free_list(t_params *x);
int						main(int ac, char **av);
int						check_nbr_ants(t_params *x);
void					error(void);
char					*ft_parse(t_params *x);
size_t					hashe(char *str);
void					define_flags(char *line, t_params *x);
int						parse_room(char *line);
void					ft_data_adjlist(t_params *x);
void					split_name_room(char **line);
char					**ft_free_db_tab(char **av);
void					free_tab(t_params *x);
void					free_queue(t_queue *q);
void					refresh_visited(t_params *x);
void					refresh_tab(t_queue *q, t_params *x);
void					print_path(t_list_path *head, t_params *x);
void					reverse_path(t_list_path *first);
int						path_ants_counts(t_list_path **tmp, size_t *nbr_ants);
void					path_ants_count(t_list_path *first, t_params *x);
void					print(int index, char *str);
int						*ft_index_zero(t_params *x);
void					set_index(t_list_path *first, t_params *x);

#endif
