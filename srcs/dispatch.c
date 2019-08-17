/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:41:12 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/16 23:45:58 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_printindex(t_params *x, int **index, int step, int *path)
{
	while (step > 0)
	{
		if ((*index)[step] != 0)
		{
			print((*index)[step], ACCESS_HASH(path[step], name));
			(*index)[step + 1] = (*index)[step];
			(*index)[step] = 0;
		}
		step--;
	}
	if (x->count_ants != 0)
	{
		(*index)[1] = x->count_ants;
		print((*index)[1], ACCESS_HASH(path[0], name));
	}
}

int		dispatch_end_path(int *index, int step)
{
	int i;

	i = 1;
	while (step >= i)
	{
		if (index[i] != 0)
			return (1);
		i++;
	}
	return (0);
}

void	ex_path(t_list_path *tmp, t_params *x, int *turn)
{
	x->count_ants = 0;
	set_printindex(x, &tmp->index, tmp->step, tmp->path);
	if (dispatch_end_path(tmp->index, tmp->step) == 0)
		(*turn)--;
	if (tmp->next == NULL)
		ft_putchar('\n');
}

void	execute_path(t_list_path *first, t_params *x, int turn)
{
	t_list_path		*tmp;
	int				save;

	save = turn;
	x->count_ants = 0;
	while (turn != 0)
	{
		turn = save;
		tmp = first;
		while (tmp != NULL)
		{
			if (tmp->ants == 0)
				ex_path(tmp, x, &turn);
			else
			{
				x->count_ants++;
				set_printindex(x, &tmp->index, tmp->step, tmp->path);
				tmp->ants--;
				if (tmp->next == NULL)
					ft_putchar('\n');
			}
			tmp = tmp->next;
		}
	}
}

void	dispatch(t_params *x, t_list_path *first)
{
	t_list_path		*tmp;
	int				turn;

	tmp = first;
	turn = 0;
	reverse_path(first);
	path_ants_count(first, x);
	set_index(first, x);
	while (tmp != NULL)
	{
		turn++;
		tmp = tmp->next;
	}
	execute_path(first, x, turn);
}
