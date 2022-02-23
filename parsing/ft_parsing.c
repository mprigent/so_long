/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:18:02 by mprigent          #+#    #+#             */
/*   Updated: 2021/09/28 03:55:44 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_parse(t_long *conf, char *argv)
{
	ft_ber_check(argv, conf);
	ft_get_coord(conf, argv);
	ft_malloc_map(conf);
	ft_stock_map(conf, argv);
	ft_check_map(conf);
	ft_check_walls(conf, argv);
	return (0);
}
