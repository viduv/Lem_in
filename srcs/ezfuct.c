/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ezfuct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 21:06:57 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/09 01:43:40 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void                init_hash_struct(t_params *x, char *line)
{
    x->hash_table[(hashe(line) % N_ROOM_MAX)].head = NULL;
    x->hash_table[(hashe(line) % N_ROOM_MAX)].name = ft_strdup(line);
}
 int                parse_edge_adjlist(char *line, t_params *x)
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

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void            split_name_room(char **line) 
{
    int len = ft_strlen(*line);
    char *space = ft_strchr(*line, ' ');
    ft_bzero(space, len - (space - *line));
}
