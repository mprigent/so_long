/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:35:50 by mprigent          #+#    #+#             */
/*   Updated: 2021/10/06 20:00:34 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_render(t_long *conf)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	while (i < conf->y_screen)
	{
		while (u < conf->x_screen)
		{
			mlx_put_image_to_window(conf->mlx, conf->win,
				conf->text[ft_find_text(conf, u, i)], u, i);
			u += 64;
		}
		u = 0;
		i += 64;
	}
	return (0);
}

int	ft_find_text(t_long *conf, int x, int y)
{
	char	c;

	c = conf->map[y / 64][x / 64];
	if (c == '1')
		return (1);
	if (c == '0')
		return (0);
	if (c == 'P')
		return (0);
	if (c == 'C')
		return (4);
	if (c == 'E')
		return (3);
	return (-1);
}

int	ft_mini(t_long *conf)
{
	ft_render(conf);
	ft_pos_player(conf);
	return (0);
}
