/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:01:11 by viduvern          #+#    #+#             */
/*   Updated: 2019/03/12 11:01:27 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	int i;

	i = 0;
	while (s1[i])
		i++;
	if (n > 0)
	{
		while (*s2 && n-- > 0)
			s1[i++] = *(s2++);
		s1[i] = '\0';
	}
	return (s1);
}
