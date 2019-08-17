/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:41:12 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/16 19:15:40 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

int                 path_ants_counts(t_list_path **tmp, size_t *nbr_ants)
{
    (*tmp)->ants++;
    (*nbr_ants)++;
     if((*tmp)->next != NULL && (*tmp)->ants + (*tmp)->step > (*tmp)->next->step) 
      {
        (*tmp) = (*tmp)->next;
        return(1);
      }
      return(0);
}
void                path_ants_count(t_list_path *first, t_params *x)
{
    t_list_path *tmp;
    size_t nbr_ants;

    nbr_ants = 0;
    while(nbr_ants < x->nbr_ants)
    {
        tmp = first;
        while(tmp != NULL && nbr_ants < x->nbr_ants)
            if(nbr_ants > 0)
             {
                 if(path_ants_counts(&tmp, &nbr_ants) == 1)
                    ;
                else 
                    break;
             }
             else
                while(nbr_ants < x->nbr_ants)
                {
                    if( tmp->next && tmp->ants + tmp->step > tmp->next->step)
                    {
                        tmp = tmp->next;
                        break;
                    }
                    tmp->ants++;
                    nbr_ants++;
                }
    }
}

void                print(int index, char *str)
{
        ft_putchar('L');
        ft_putnbr(index);
        ft_putchar('-');
        ft_putstr(str);
        ft_putchar(' ');
}
int                 *ft_index_zero(t_params *x)
{
    int *index;
    int i;

    i = 0;
    index = (int*)malloc(sizeof(int) * x->nbr_room);
    while(i < x->nbr_room)
    {
        index[i] = 0;
        i++;
    }
    return(index);
}
void                set_index(t_list_path *first, t_params *x)
{
    t_list_path *tmp;
    tmp = first;
    
    while(tmp != NULL)
    {
        tmp->index = ft_index_zero(x);
        tmp = tmp->next;
    }

}

void                set_printindex(int ants, t_params *x, int **index, int step, int *path)
{
    while(step > 0)
    {
        if((*index)[step] != 0)
        {
            print((*index)[step], ACCESS_HASH(path[step], name));
            (*index)[step + 1] = (*index)[step];
            (*index)[step] = 0;
        }
        step--;
    }
    if(ants != 0)
    {
        (*index)[1] = ants;
        print((*index)[1], ACCESS_HASH(path[0], name));
    }
}   

int          dispatch_end_path(int *index, int step)
{
     int i = 1;
    while(step >= i)
    {
        if(index[i] != 0)
            return(1);
        i++;
    }
    return(0);
}

void                ex_path(t_list_path *tmp, t_params *x, int *turn)
 {
    set_printindex(0, x, &tmp->index, tmp->step, tmp->path);
    if(dispatch_end_path(tmp->index, tmp->step) == 0)
        (*turn)--;
    if(tmp->next == NULL)
        ft_putchar('\n');
}
void                execute_path(t_list_path *first, t_params *x, int turn)
{
    t_list_path *tmp;
    int save;
    size_t ants;

    save = turn;
    ants = 0;
    while(turn != 0)
    {
        turn = save;
        tmp = first;
        while(tmp != NULL)
         {
             if(tmp->ants == 0)
                ex_path(tmp, x, &turn);
            else
            {
                ants++;
                set_printindex(ants, x, &tmp->index, tmp->step , tmp->path);
                 tmp->ants--;
                 if(tmp->next == NULL)
                     ft_putchar('\n');
            }
            tmp = tmp->next;
          }
    }
}

void                dispatch(t_params *x, t_list_path *first)
{
    t_list_path *tmp;
    (void)x;
    tmp = first;
    int turn;

    turn = 0;
    reverse_path(first);
    path_ants_count(first, x);
    set_index(first, x);
    while(tmp != NULL)
    {
        turn++;
        tmp = tmp->next;
    }
    execute_path(first,x, turn);
}