/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 23:19:46 by mprigent          #+#    #+#             */
/*   Updated: 2021/11/02 20:11:50 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_print_err(char *msg)
{
	ft_putendl_fd("\033[31mError.\033[0;37m", STDOUT_FILENO);
	ft_putendl_fd(msg, STDOUT_FILENO);
	return (1);
}

int	ft_print_error2(t_long *conf, char *str)
{
	write(1, "\033[31mError\n\033[0;37m", 12);
	ft_putstr(str);
	write(1, "\n", 1);
	ft_exit_free(conf);
	return (0);
}
