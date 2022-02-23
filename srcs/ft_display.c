/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:50:54 by mprigent          #+#    #+#             */
/*   Updated: 2021/10/07 20:10:12 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_display(t_long *conf)
{
	ft_init_window(conf);
	ft_load_text(conf);
	ft_render(conf);
	write(1, "\033[32m[ so_long launch successfully ]\033[00m\n", 43);
	ft_pos_player(conf);
	ft_hooks(conf);
	return (0);
}

int	ft_hooks(t_long *conf)
{
	mlx_hook(conf->win, 2, 1L, ft_key_hit, conf);
	mlx_hook(conf->win, 15, 1L << 16, ft_mini, conf);
	mlx_hook(conf->win, CLOSERED, 1L << 17, ft_red_button, conf);
	mlx_loop_hook(conf->mlx, ft_key_loop, conf);
	mlx_loop(conf->mlx);
	return (0);
}

int	ft_key_loop(t_long *conf)
{
	if (conf->keyboard[ESC] == 1 || conf->keyboard[RIGHT] == 1
		|| conf->keyboard[LEFT] == 1 || conf->keyboard[BACK] == 1
		|| conf->keyboard[ADVANCE] == 1)
	{
		ft_keyboard(conf);
		ft_reset_keyboard(conf);
		ft_pos_player(conf);
	}
	return (0);
}

int	ft_red_button(t_long *conf)
{
	ft_exit_free(conf);
	conf->keyboard[79] = 1;
	return (0);
}
