/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:41:12 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/14 01:14:03 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


// void                print_final(int **pathfull, int ants, t_params *x)
// {
//     (void)ants;
//     // int i = 0;
//     // int x = 0;
//     ft_putendl(ACCESS_HASH(pathfull[0][0] ,name));
//     ft_putendl(ACCESS_HASH(pathfull[0][1] ,name));
//     ft_putendl(ACCESS_HASH(pathfull[0][2] ,name));

// }
void                reverse_path(t_list_path *first)
{
    t_list_path *tmp;
    tmp = first;
    while(tmp != NULL)
    {
        tmp->path = reverse_integer(tmp->path);
        tmp = tmp->next;
    }
}

int                 check_simple_path(t_list_path *first, t_params *x)
{
    if(first->next == NULL)
    {
        first->ants = x->nbr_ants;
        return(1);
    }
    if(x->nbr_ants < (size_t)first->step)
    {
        first->ants = x->nbr_ants;
        return(1);
    } 
    return(0);
}
void                path_ants_count(t_list_path *first, t_params *x)
{
    t_list_path *tmp;
    size_t nbr_ants;

    nbr_ants = 0;
    if(check_simple_path(first, x) == 1)
        return ;
    while(nbr_ants < x->nbr_ants)
    {
        tmp = first;
        while(tmp != NULL && nbr_ants < x->nbr_ants)
            if(nbr_ants > 0)
             {
                tmp->ants++;
                nbr_ants++;
                if(tmp->next != NULL && tmp->ants + tmp->step > tmp->next->step) 
                    tmp = tmp->next;
                else 
                    break;
             }
             else
                while(nbr_ants < x->nbr_ants)
                {
                    if(tmp->ants + tmp->step > tmp->next->step)
                    {
                        tmp = tmp->next;
                        break;
                    }
                    tmp->ants++;
                    nbr_ants++;
                }
    }
}

void                print_realpath(t_params *x, t_list_path *first)
{
    char *tmp;
    tmp = first;
    int index;

    index = 0;
    while(tmp != NULL)
    {
        print_ants(index);

    }

}
void                dispatch(t_params *x, t_list_path *first)
{
    t_list_path *tmp;
    (void)x;
    tmp = first;
    reverse_path(first);
    path_ants_count(first, x);
    print_path(first);
}
//     pathfull = (int**)malloc(sizeof(int*) * i);
//     tmp = first;
//     while(tmp != NULL)
//     {
//         if(i == 0)
//             break;
//        pathfull[s] = tmp->path;
//        tmp = tmp->next;
//         i--;
//         s++;
//     } 
//    print_final(pathfull, nbr_ants, x);  