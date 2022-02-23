/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:26:17 by mprigent          #+#    #+#             */
/*   Updated: 2021/09/28 02:43:52 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_get_coord(t_long *conf, char *so_long)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(so_long, O_RDONLY);
	ret = get_next_line(fd, &line);
	conf->allx = ft_strlen(line);
	while (line[ft_check(line)] == '1' || line[ft_check(line)] == '0')
	{
		conf->x = ft_strlen(line);
		if (conf->x != conf->allx)
		{
			ft_print_err(NOT_RECTANGULAR);
			ft_exit_free(conf);
		}
		free(line);
		ret = get_next_line(fd, &line);
		conf->y++;
	}
	free(line);
	close(fd);
	return (0);
}
