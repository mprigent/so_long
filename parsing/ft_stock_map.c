/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:51:15 by mprigent          #+#    #+#             */
/*   Updated: 2021/11/02 19:35:27 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_stock_map(t_long *conf, char *so_long)
{
	char		*line;
	int			fd;
	int			ret;

	fd = open(so_long, O_RDONLY);
	ret = get_next_line(fd, &line);
	while (conf->d != conf->y)
	{
		ft_gnl_line(conf, line);
		while (conf->t != conf->x)
		{
			conf->map[conf->d][conf->t] = line[conf->t];
			if (conf->map[conf->d][conf->t] == 'P')
				conf->player_y = conf->d;
			if (conf->map[conf->d][conf->t] == 'P')
				conf->player_x = conf->t;
			conf->t++;
		}
		free(line);
		ret = get_next_line(fd, &line);
		conf->t = 0;
		conf->d++;
	}
	free(line);
	return (0);
}
