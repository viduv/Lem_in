/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:03:36 by viduvern          #+#    #+#             */
/*   Updated: 2019/03/12 11:03:58 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int test;

	i = 0;
	test = -1;
	while (s[i])
	{
		if (c == 0)
			return ((char *)(s + ft_strlen(s)));
		if (s[i] == (char)c)
			test = i;
		i++;
	}
	if (test != -1)
		return ((char *)(s + test));
	else
		return ((void *)NULL);
}
