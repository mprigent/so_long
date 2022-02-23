/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:42:17 by mprigent          #+#    #+#             */
/*   Updated: 2021/10/07 19:57:06 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_malloc_map(t_long *conf)
{
	int	i;

	i = 0;
	conf->map = malloc(sizeof(char *) * conf->y);
	while (i < conf->y)
	{
		conf->map[i] = malloc(sizeof(char) * (conf->x + 1));
		if (!conf->map[i])
		{
			ft_print_err(MALLOC_ERROR);
			ft_exit_free(conf);
		}
		i++;
	}
	conf->free_map = 1;
	return (1);
}
