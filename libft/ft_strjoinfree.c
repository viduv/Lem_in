/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 12:05:53 by viduvern          #+#    #+#             */
/*   Updated: 2019/03/15 14:34:06 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoinfree(char const *s1, char const *s2)
{
	char	*s;

	s = ft_strjoin(s1, s2);
	free(&s1);
	free(&s2);
	return (s);
}
