/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:41:12 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/13 15:25:43 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


void                print_final(int **pathfull, int ants, t_params *x)
{
    (void)ants;
    // int i = 0;
    // int x = 0;
    ft_putendl(ACCESS_HASH(pathfull[0][0] ,name));
    ft_putendl(ACCESS_HASH(pathfull[0][1] ,name));
    ft_putendl(ACCESS_HASH(pathfull[0][2] ,name));

}
void                dispatch(t_params *x, t_list_path *first)
{
    int nbr_ants;
    t_list_path *tmp;
    int step = 0;
    int i = 0;
    int s = 0;
    int **pathfull;
    tmp = first;
    nbr_ants = x->nbr_ants;
    while(tmp != NULL)
    {
        step += tmp->step;
        if(nbr_ants < step)
            break;
        tmp = tmp->next;
        i++;
    }
    pathfull = (int**)malloc(sizeof(int*) * i);
    tmp = first;
    while(tmp != NULL)
    {
        if(i == 0)
            break;
       pathfull[s] = reverse_integer(tmp->path);
       tmp = tmp->next;
        i--;
        s++;
    } 
   print_final(pathfull, nbr_ants, x);  
}