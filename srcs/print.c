/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:56:45 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/16 23:25:07 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print(int index, char *str)
{
	ft_putchar('L');
	ft_putnbr(index);
	ft_putchar('-');
	ft_putstr(str);
	ft_putchar(' ');
}
