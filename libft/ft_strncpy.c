/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:02:01 by viduvern          #+#    #+#             */
/*   Updated: 2019/03/12 11:02:14 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *restrict dst, const char *restrict src, size_t n)
{
	int i;

	i = 0;
	while (n-- > 0)
		if (*src)
			dst[i++] = *src++;
		else
			dst[i++] = '\0';
	return (dst);
}
