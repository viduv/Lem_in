/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitpatab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:04:09 by viduvern          #+#    #+#             */
/*   Updated: 2019/03/24 13:50:44 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	int		ft_countwords(char const *s, char c, char x)
{
	int i;
	int split;

	i = 0;
	split = 0;
	while (*s)
	{
		if ((split == 1 && *s == c) || (split == 1 && *s == x))
			split = 0;
		if ((split == 0 && *s != c) || (split == 0 && *s != x))
		{
			split = 1;
			i++;
		}
		s++;
	}
	return (i);
}

static	int		ft_countchar(char const *s, char c, char x)
{
	int i;

	i = 0;
	while ((*s && *s++ != c) || (*s && *s++ != x))
		i++;
	return (i);
}

char			**ft_strsplitpatab(char const *s, char c, char x)
{
	int		i;
	int		nb_words;
	char	**tab;

	if (!c || s == NULL)
		return (NULL);
	nb_words = ft_countwords(s, c, x);
	tab = (char **)malloc(sizeof(*tab) * (nb_words + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (nb_words--)
	{
		while ((*s == c && *s) || (*s == x && *s))
			s++;
		tab[i] = ft_strsub((const char *)s, 0,
		ft_countchar((const char *)s, c, x));
		if (tab[i++] == NULL)
			return (NULL);
		s = s + ft_countchar((const char *)s, c, x);
	}
	tab[i] = NULL;
	return (tab);
}
