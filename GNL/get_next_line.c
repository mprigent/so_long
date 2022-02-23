/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:54:56 by mprigent          #+#    #+#             */
/*   Updated: 2021/10/25 20:44:47 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*recurs(int depth, int *ret, int fd)
{
	char	buff[1];
	char	*lines;
	int		files;

	files = read(fd, buff, 1);
	if (files == 0)
		buff[0] = 0;
	if (buff[0] == '\n' || buff[0] == 0)
	{
		lines = malloc(sizeof(char) * depth + 1);
		if (!lines)
			return (0);
		lines[depth] = 0;
		*ret = 1;
		if (buff[0] == 0)
			*ret = 0;
		return (lines);
	}
	else
	{
		lines = recurs(depth + 1, ret, fd);
		lines[depth] = buff[0];
	}
	return (lines);
}

int	get_next_line(int fd, char **lines)
{
	int	ret;

	ret = 1;
	*lines = recurs(0, &ret, fd);
	return (ret);
}
