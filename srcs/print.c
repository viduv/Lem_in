/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:56:45 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/08 21:54:45 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void                       print_list(t_params *x, char *room)
{
     t_linked_list *print = x->hash_table[(hashe(room) % N_ROOM_MAX)].head;
     int a = 0;

     while(print != NULL)
     {
          ft_putstr(x->hash_table[print->data].name);
          ft_putchar('\n');
          print = print->next;
          a++;
     }
     printf("**************%d\n*********", a);
}
// void                     print_imputfile(t_params *x)
   // while(x.storefile[z])
    //  {
    //     ft_putendl(x.storefile[z]);
    //     z++;
    //  }
    //  z = 0;
    //  while(z < 100000)
    //  {  
    //      if(x.hash_table[z].name != NULL)
    //             ft_strdel(&x.hash_table[50].name);
    //     z++;
    ////  }