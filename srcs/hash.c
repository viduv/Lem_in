/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 01:21:41 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/16 20:16:52 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t			hashe(char *str)
{
	unsigned int	i;
	unsigned int	hash;

	hash = FNV_OFFSET_32;
	i = 0;
	while (str[i])
	{
		hash ^= str[i];
		hash *= FNV_PRIME_32;
		i += 1;
	}
	return ((size_t)hash);
}
