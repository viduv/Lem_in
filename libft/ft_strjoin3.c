/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 10:59:01 by viduvern          #+#    #+#             */
/*   Updated: 2019/03/22 10:13:29 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin3(char const *s1, char const *s2, char const *s3)
{
	char	*s;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	s = (char *)malloc(sizeof(*s) * (len + 1));
	if (s == NULL || s1 == NULL || s2 == NULL)
		return (NULL);
	ft_strcpy(s, s1);
	ft_strcat(s, s2);
	ft_strcat(s, s3);
	return (s);
}
