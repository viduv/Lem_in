/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ezfuct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 21:06:57 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/16 20:11:09 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		*reverse_integer(int *tab)
{
	int z;
	int i;
	int tmp;

	i = 0;
	z = 0;
	while (tab[z] != 0)
		z++;
	while (i < (z / 2))
	{
		tmp = tab[i];
		tab[i] = tab[z - i - 1];
		tab[z - i - 1] = tmp;
		i++;
	}
	return (tab);
}

int		is_empty(t_queue *q)
{
	if (q->rear == -1)
		return (1);
	else
		return (0);
}

void	init_hash_struct(t_params *x, char *line)
{
	int index;

	index = hashe(line) % N_ROOM_MAX;
	while (x->hash_table[index].name != NULL)
		index++;
	x->hash_table[index].head = NULL;
	x->hash_table[index].name = ft_strdup(line);
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	split_name_room(char **line)
{
	int		len;
	char	*space;

	len = ft_strlen(*line);
	space = ft_strchr(*line, ' ');
	ft_bzero(space, len - (space - *line));
}
