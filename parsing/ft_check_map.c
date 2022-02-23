/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:37:37 by mprigent          #+#    #+#             */
/*   Updated: 2021/10/25 20:39:08 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_check_map(t_long *conf)
{
	if (conf->set_player < 1)
	{
		ft_print_err(MISSING_PLAYER_POS);
		ft_exit_free(conf);
	}
	if (conf->set_exit < 1)
	{
		ft_print_err(NO_EXIT_GATE);
		ft_exit_free(conf);
	}
	if (conf->set_exit > 1 || conf->set_collectibles == 0
		|| conf->set_player > 1)
	{
		ft_print_err(NOT_VALID_MAP);
		ft_exit_free(conf);
	}
	return (0);
}
