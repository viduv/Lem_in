/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 10:25:32 by viduvern          #+#    #+#             */
/*   Updated: 2019/03/15 09:43:26 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	*clean(char *str)
{
	while (*str == '\n' || *str == '\v' ||
			*str == '\t' || *str == '\r' ||
			*str == '\f' || *str == ' ')
		str++;
	return (str);
}

int			ft_atoi(char *str)
{
	int result;

	result = 0;
	str = clean(str);
	if (*str == '-' && ft_isdigit(*(str + 1)))
	{
		result = 0 - (*(str + 1) - '0');
		while (ft_isdigit(*(str + 2)))
			result = result * 10 - (*(str++ + 2) - '0');
	}
	else if (*str == '+' && ft_isdigit(*(str + 1)))
	{
		result = *(str + 1) - '0';
		while (ft_isdigit(*(str + 2)))
			result = result * 10 + (*(str++ + 2) - '0');
	}
	else if (ft_isdigit(*str))
	{
		result = *str - '0';
		while (ft_isdigit(*(str + 1)))
			result = result * 10 + *(str++ + 1) - '0';
	}
	else
		return (0);
	return (result);
}
