/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 10:40:52 by viduvern          #+#    #+#             */
/*   Updated: 2019/03/17 12:25:53 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int i;

	i = -1;
	while ((size_t)++i < n)
		if ((unsigned char)c == ((unsigned char *)s)[i])
			return ((char *)s + i);
	return (NULL);
}
