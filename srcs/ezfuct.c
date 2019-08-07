/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ezfuct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 21:06:57 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/06 02:15:18 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
 int                parse_edge(char *line, t_params *x)
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

void            allocspace(char **line)
{
    int i;
    int x;

    x = 0;
    i = 0;
    while((*line)[i])
        i++;
    x = i;
    i = 0;
    while((*line)[i] != ' ')
        i++;
    while((*line)[i] && i < x)
    {
        (*line)[i] = 0;
        i++;
    }
}