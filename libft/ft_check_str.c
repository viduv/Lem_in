/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:57:43 by viclucas          #+#    #+#             */
/*   Updated: 2019/07/31 01:39:31 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_check_str(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && i < 1)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
