/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:41:12 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/16 04:34:18 by viduvern         ###   ########.fr       */
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
    // if(x->nbr_ants < (size_t)first->step)
    // {
    //     first->ants = x->nbr_ants;
    //     return(1);
    // } 
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

void          dispatch_end_path(t_list_path *first, t_params *x)
{
    t_list_path *tmp;
    ft_putendl("ENDDD");
    tmp = first;
    int i = 0;
   // while(tmp->index[tmp->step] != (int)x->nbr_ants)
      //  while(i < 37)
        {
         while(tmp != NULL)
            {
                set_printindex(0, x, &tmp->index, tmp->step, tmp->path);
                if(tmp->next == NULL)
                   ft_putchar('\n');
                tmp = tmp->next;
            }
           tmp = first;
           i++; 
        }
     ft_putchar('L');
     ft_putnbr(x->nbr_ants);
     ft_putchar(' ');
     ft_putendl(ACCESS_HASH(tmp->path[tmp->step], name));
}

void                execute_path(t_list_path *first, t_params *x)
{
    t_list_path *tmp;
    size_t ants = 0;
    tmp = first;
    while(ants < x->nbr_ants)
    {
        tmp = first;
        while(tmp != NULL)
         {
             if(tmp->ants == 0)
            {
                ft_putchar('\n');
                break;
            }
            ants++;
            set_printindex(ants, x, &tmp->index, tmp->step , tmp->path);
            tmp->ants--;
            if(tmp->next == NULL)
            {
                ft_putchar('\n');
                break;
            }
            tmp = tmp->next;
          }
    }
   dispatch_end_path(first, x);
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
    print_path(first, x);
    set_index(first, x);
    execute_path(first,x);
}
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