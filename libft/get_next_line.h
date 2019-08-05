/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 07:37:40 by viclucas          #+#    #+#             */
/*   Updated: 2019/07/25 16:55:05 by viduvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include "includes/libft.h"
# include <stdio.h>
# include <stdlib.h>
# define BUFF_SIZE 10
# define MAX_FD 5000

int		get_next_line(int fd, char **line);
int		clear_buffer(int fd, char **line, char **fds);
int		newline_buffer(int fd, char **line, char **fds);
#endif