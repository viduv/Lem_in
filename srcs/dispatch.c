/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:41:12 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/16 23:39:45 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_printindex(int ants, t_params *x, int **index, int step, int *path)
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
	if (ants != 0)
	{
		(*index)[1] = ants;
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
	set_printindex(0, x, &tmp->index, tmp->step, tmp->path);
	if (dispatch_end_path(tmp->index, tmp->step) == 0)
		(*turn)--;
	if (tmp->next == NULL)
		ft_putchar('\n');
}

void	execute_path(t_list_path *first, t_params *x, int turn)
{
	t_list_path		*tmp;
	int				save;
	size_t			ants;

	save = turn;
	ants = 0;
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
				ants++;
				set_printindex(ants, x, &tmp->index, tmp->step, tmp->path);
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
