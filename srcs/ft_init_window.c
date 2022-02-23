/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:17:52 by mprigent          #+#    #+#             */
/*   Updated: 2021/10/07 20:01:02 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_init_window(t_long *conf)
{
	conf->y_screen = conf->y * 64;
	conf->x_screen = conf->x * 64;
	conf->mlx = mlx_init();
	if (!conf->mlx)
	{
		ft_print_err(MLX_ERROR);
		ft_exit_free(conf);
	}
	conf->img = mlx_new_image(conf->mlx, conf->x_screen, conf->y_screen);
	conf->pxl = mlx_get_data_addr(conf->img, &conf->bits_per_pxl[5],
			&conf->s_line[5], &conf->ed_text[5]);
	conf->win = mlx_new_window(conf->mlx, conf->x_screen,
			conf->y_screen, "so_long mprigent");
	return (0);
}
