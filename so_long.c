/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:28:39 by mprigent          #+#    #+#             */
/*   Updated: 2021/10/25 20:40:25 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	main(int argc, char **argv)
{
	t_long	so_long;
	int		i;

	i = 0;
	ft_init_var(&so_long);
	if (argc != 2)
	{
		ft_print_err(INVALID_ARGS);
		ft_exit_free(&so_long);
	}
	ft_parse(&so_long, argv[1]);
	ft_display(&so_long);
	return (0);
}
