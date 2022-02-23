/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:35:37 by mprigent          #+#    #+#             */
/*   Updated: 2021/09/28 01:32:07 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_keyboard(t_long *conf)
{
	if (conf->keyboard[ADVANCE])
		ft_move_player(conf, 1);
	if (conf->keyboard[BACK])
		ft_move_player(conf, -1);
	if (conf->keyboard[LEFT])
		ft_move_player(conf, 2);
	if (conf->keyboard[RIGHT])
		ft_move_player(conf, 3);
	if (conf->keyboard[ESC] == 1 || conf->keyboard[RED_BUTTON] == 1)
		ft_exit_free(conf);
	return (0);
}

int	ft_key_hit(int keycode, t_long *conf)
{
	conf->keyboard[keycode] = 1;
	return (0);
}

int	ft_reset_keyboard(t_long *conf)
{
	conf->keyboard[ADVANCE] = 0;
	conf->keyboard[BACK] = 0;
	conf->keyboard[LEFT] = 0;
	conf->keyboard[RIGHT] = 0;
	conf->keyboard[ESC] = 0;
	conf->keyboard[RED_BUTTON] = 0;
	return (0);
}
