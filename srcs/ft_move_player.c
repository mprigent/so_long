/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:21:58 by mprigent          #+#    #+#             */
/*   Updated: 2021/10/08 16:25:58 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_move_player(t_long *conf, int nb)
{
	if (nb == -1)
		if (conf->map[conf->player_y + 1][conf->player_x] != '1')
			ft_move_count(conf, nb);
	if (nb == 1)
		if (conf->map[conf->player_y - 1][conf->player_x] != '1')
			ft_move_count(conf, nb);
	if (nb == 2)
		if (conf->map[conf->player_y][conf->player_x - 1] != '1')
			ft_move_count(conf, nb);
	if (nb == 3)
		if (conf->map[conf->player_y][conf->player_x + 1] != '1')
			ft_move_count(conf, nb);
	return (0);
}

int	ft_move_count(t_long *conf, int nb)
{
	if (nb == -1)
		conf->player_y++;
	if (nb == 1)
		conf->player_y--;
	if (nb == 2)
		conf->player_x--;
	if (nb == 3)
		conf->player_x++;
	conf->move_count++;
	write(1, "\b\b\b\b\b\b\b\b\b\b\b", 12);
	write(1, "MOVE : ", 8);
	ft_putnbr(conf->move_count);
	return (0);
}

int	ft_pos_player(t_long *conf)
{
	if (conf->lastplayer_x != -1)
	{
		mlx_put_image_to_window(conf->mlx, conf->win,
			conf->text[ft_find_text(conf, conf->lastplayer_x * 64,
				conf->lastplayer_y * 64)], conf->lastplayer_x * 64,
			conf->lastplayer_y * 64);
	}
	mlx_put_image_to_window(conf->mlx, conf->win, conf->text[2],
		conf->player_x * 64, conf->player_y * 64);
	conf->lastplayer_x = conf->player_x;
	conf->lastplayer_y = conf->player_y;
	ft_collectibles(conf);
	return (0);
}

void	ft_collectibles(t_long *conf)
{
	if (conf->map[conf->player_y][conf->player_x] == 'C')
	{
		conf->collectibles++;
		conf->map[conf->player_y][conf->player_x] = '0';
	}
	if (conf->map[conf->player_y][conf->player_x] == 'E')
	{
		if (conf->collectibles == conf->set_collectibles)
		{
			write(1, "\033[32m \nCongratulations !\033[00m Final score : ", 45);
			ft_putnbr(conf->move_count);
			write(1, " moves.\n", 9);
			ft_exit_free(conf);
		}
		else
			ft_print_err(CANT_EXIT);
	}
}
