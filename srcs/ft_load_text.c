/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 23:16:42 by mprigent          #+#    #+#             */
/*   Updated: 2021/10/07 23:23:27 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_load_text(t_long *conf)
{
	conf->text[0] = mlx_xpm_file_to_image(conf->mlx, "./textures/sand.xpm",
			&conf->x_text[0], &conf->y_text[0]);
	conf->text[1] = mlx_xpm_file_to_image(conf->mlx, "./textures/wall.xpm",
			&conf->x_text[1], &conf->y_text[1]);
	conf->text[2] = mlx_xpm_file_to_image(conf->mlx,
			"./textures/player_right.xpm", &conf->x_text[2], &conf->y_text[2]);
	conf->text[3] = mlx_xpm_file_to_image(conf->mlx, "./textures/exit.xpm",
			&conf->x_text[3], &conf->y_text[3]);
	conf->text[4] = mlx_xpm_file_to_image(conf->mlx, "./textures/coin1.xpm",
			&conf->x_text[4], &conf->y_text[4]);
	conf->text[5] = mlx_xpm_file_to_image(conf->mlx, "./textures/coin2.xpm",
			&conf->x_text[5], &conf->y_text[4]);
	ft_load_text2(conf);
	return (0);
}

int	ft_load_text2(t_long *conf)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (!conf->text[i])
		{
			ft_print_err(TEXT_ERROR);
			ft_exit_free(conf);
		}
		conf->text_ptr[i] = mlx_get_data_addr(conf->text[i],
				&conf->bits_per_pxl[i], &conf->ed_text[i], &conf->s_line[i]);
		i++;
	}
	return (0);
}
