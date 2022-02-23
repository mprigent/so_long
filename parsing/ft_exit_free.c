/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 23:19:11 by mprigent          #+#    #+#             */
/*   Updated: 2021/11/02 20:03:01 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_exit_free(t_long *conf)
{
	if (conf->mlx != NULL)
		mlx_destroy_window(conf->mlx, conf->win);
	if (conf->map != NULL)
		ft_free_map(conf);
	exit(0);
}
