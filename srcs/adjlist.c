/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:43:16 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/16 22:06:45 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_linked_list	*c_node_adjlist(int index)
{
	t_linked_list *q;

	q = (t_linked_list*)malloc(sizeof(t_linked_list));
	q->data = index;
	q->visited = false;
	q->path = false;
	q->step = 0;
	q->next = NULL;
	return (q);
}

static void		add_edge_adjlist(int index_src, int index_dest, t_params *x)
{
	t_linked_list *tmp;

	tmp = c_node_adjlist(index_dest);
	tmp->next = x->hash_table[index_src].head;
	x->hash_table[index_src].head = tmp;
	tmp = c_node_adjlist(index_src);
	tmp->next = x->hash_table[index_dest].head;
	x->hash_table[index_dest].head = tmp;
}

static void		set_index_adjlist(char *line, t_params *x)
{
	char	**str;
	int		index_src;
	int		index_dest;

	str = ft_strsplit(line, '-');
	index_src = hashe(str[0]) % N_ROOM_MAX;
	index_dest = hashe(str[1]) % N_ROOM_MAX;
	while (strcmp(str[0], x->hash_table[index_src].name) != 0)
		index_src++;
	while (strcmp(str[1], x->hash_table[index_dest].name) != 0)
		index_dest++;
	ft_free_db_tab(str);
	add_edge_adjlist(index_src, index_dest, x);
}

static void		parse_edge_adjlist(char *line, t_params *x)
{
	char	**str;
	int		i;
	int		index;
	int		index2;

	i = 0;
	str = ft_strsplit(line, '-');
	index = hashe(str[0]) % N_ROOM_MAX;
	index2 = hashe(str[1]) % N_ROOM_MAX;
	if (str[2])
		error();
	if (strcmp(str[0], x->hash_table[index].name) == 0)
		i++;
	else
		while (index < N_ROOM_MAX && i < 1)
			strcmp(str[0], x->hash_table[index].name) == 0 ? i++ : index++;
	if (strcmp(str[1], x->hash_table[index2].name) == 0)
		i++;
	else
		while (index2 < N_ROOM_MAX && i < 2)
			strcmp(str[1], x->hash_table[index2].name) == 0 ? i++ : index2++;
	ft_free_db_tab(str);
	if (i != 2)
		error();
}

void			ft_data_adjlist(t_params *x)
{
	char *line;

	parse_edge_adjlist(x->tmp, x);
	set_index_adjlist(x->tmp, x);
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		ft_putendl(line);
		if (ft_check_str(line, '#') != 1 && ft_check_str(line, 'L') != 1)
		{
			parse_edge_adjlist(line, x);
			set_index_adjlist(line, x);
		}
		ft_strdel(&line);
	}
	split_name_room(&x->start);
	split_name_room(&x->end);
}
