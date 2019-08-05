/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 21:05:31 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/03 13:20:01 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		**ft_free_db_tab(char **av)
{
	int i;

	i = 0;
	if (!av)
		return (NULL);
	while (av[i] && av[i] != NULL)
		ft_strdel(&av[i++]);
	free(av);
	av = NULL;
	return (av);
}

// void                free_tab(t_params *x)
// {
//     int z; 

//     z = 0;
//     while(z < 100000)
//     {
//         if(STR[z])
//             ft_strdel(&STR[z]);
//         z++;
//     }
// }