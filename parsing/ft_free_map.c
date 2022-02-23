/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 23:24:52 by mprigent          #+#    #+#             */
/*   Updated: 2021/09/28 02:11:00 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_free_map(t_long *conf)
{
	int	i;

	i = 0;
	if (conf->free_map == -1)
		return (1);
	while (i < conf->y)
	{
		free(conf->map[i]);
		i++;
	}
	if (conf->map)
		free(conf->map);
	return (1);
}
