/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:53:43 by mprigent          #+#    #+#             */
/*   Updated: 2021/09/28 02:11:09 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_gnl_line(t_long *conf, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			conf->set_player++;
		if (line[i] == 'E')
			conf->set_exit++;
		if (line[i] == 'C')
			conf->set_collectibles++;
		if (line[i] != 'P' && line[i] != 'E' && line[i]
			!= 'C' && line[i] != '1' && line[i] != '0')
		{
			ft_print_err(INVALID_CHARACTER);
			ft_exit_free(conf);
		}
		i++;
	}
	return (0);
}
