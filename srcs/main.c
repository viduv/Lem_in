/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:53:54 by viduvern          #+#    #+#             */
/*   Updated: 2019/08/16 22:18:56 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		define_flags(char *line, t_params *x)
{
	if (x->s == 1)
	{
		x->start = ft_strdup(line);
		x->s = 0;
	}
	else if (x->s == 2)
	{
		x->end = ft_strdup(line);
		x->s = 0;
	}
	else if (ft_strequ("##start", line))
		x->s = 1;
	else if (ft_strequ("##end", line))
		x->s = 2;
}

int			parse_room(char *line)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strdup(line);
	while (str[i] != ' ' && str[i])
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
		{
			ft_strdel(&str);
			error();
		}
		i++;
	}
	ft_strdel(&str);
	return (1);
}

char		*ft_parse(t_params *x)
{
	char *line;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		ft_putendl(line);
		if (x->s > 0 || ft_strequ("##start", line) || ft_strequ("##end", line))
			define_flags(line, x);
		if (ft_check_str(line, '#') != 1 && ft_check_str(line, 'L') != 1)
		{
			if (ft_strchr(line, '-'))
			{
				x->tmp = ft_strdup(line);
				ft_strdel(&line);
				break ;
			}
			else if (parse_room(line) == 1)
			{
				split_name_room(&line);
				init_hash_struct(x, line);
				x->nbr_room++;
			}
		}
		ft_strdel(&line);
	}
	return (x->start == NULL ? x->start : x->end);
}

int			check_nbr_ants(t_params *x)
{
	char *line;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		x->nbr_ants = atoi(line);
		ft_strdel(&line);
		break ;
	}
	ft_putnbr(x->nbr_ants);
	ft_putchar('\n');
	return (x->nbr_ants);
}

int			main(int ac, char **av)
{
	int				z;
	t_params		x;
	t_list_path		*first;

	(void)av;
	first = NULL;
	ft_bzero(&x, sizeof(t_params));
	z = 0;
	if (ac == 1)
	{
		if (check_nbr_ants(&x) <= 0)
			error();
		if (ft_parse(&x) == NULL)
			error();
		x.nbr_room < 2 ? error() : x.nbr_room;
		ft_data_adjlist(&x);
		dispatch_bfs(&x, &first);
		dispatch(&x, first);
	}
	else
		ft_putendl("\033[92m usage : ./lem_in < maps  --> One map only");
	ft_free_list(&x);
	ft_free_params(&x);
	ft_free_path(first);
	return (0);
}
