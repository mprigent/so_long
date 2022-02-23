/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:30:21 by mprigent          #+#    #+#             */
/*   Updated: 2021/09/28 03:01:22 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_init_var(t_long *conf)
{
	conf->keyboard[BACK] = 0;
	conf->keyboard[RED_BUTTON] = 0;
	conf->keyboard[ESC] = 0;
	conf->keyboard[LEFT] = 0;
	conf->keyboard[RIGHT] = 0;
	conf->keyboard[ADVANCE] = 0;
	conf->x = 0;
	conf->y = 0;
	conf->set_player = 0;
	conf->set_exit = 0;
	conf->set_collectibles = 0;
	conf->collectibles = 0;
	conf->collectibles = 0;
	conf->map = NULL;
	conf->mlx = NULL;
	conf->lastplayer_y = -1;
	conf->lastplayer_x = -1;
	conf->player_x = 0;
	conf->player_y = 0;
	conf->move_count = 0;
	ft_init_var2(conf);
	return (0);
}

int	ft_init_var2(t_long *conf)
{
	conf->allx = 0;
	conf->u = 0;
	conf->j = 0;
	conf->d = 0;
	conf->t = 0;
	return (0);
}
