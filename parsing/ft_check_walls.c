/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:48:00 by mprigent          #+#    #+#             */
/*   Updated: 2021/11/02 20:07:41 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_check_walls(t_long *conf, char *so_long)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(so_long, O_RDONLY);
	ret = get_next_line(fd, &line);
	free(line);
	while (conf->j != conf->y)
	{
		while (conf->u != conf->x)
		{
			if (conf->map[0][conf->u] != '1'
					|| conf->map[conf->y - 1][conf->u] != '1')
				ft_print_error2(conf, "EThe map is not closed by walls.");
			conf->u++;
		}
		ft_check_walls2(conf);
		ret = get_next_line(fd, &line);
		free(line);
		conf->u = 0;
		conf->j++;
	}
	return (0);
}

int	ft_check_walls2(t_long *conf)
{
	if (conf->map[conf->j][0] != '1'
		|| conf->map[conf->j][conf->x - 1] != '1')
	{
		ft_print_err(NOT_CLOSED);
		ft_exit_free(conf);
	}
	return (0);
}
