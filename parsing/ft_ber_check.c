/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ber_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:20:34 by mprigent          #+#    #+#             */
/*   Updated: 2021/09/28 02:09:41 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_ber_check(char *str, t_long *conf)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 4] == '.' && str[i - 3] == 'b'
		&& str[i - 2] == 'e' && str[i - 1] == 'r')
	{
		i = open(str, O_RDONLY);
		if (i == -1)
		{
			ft_print_err(NOT_VALID_FILE);
			ft_exit_free(conf);
		}
		else
			close(i);
		return (0);
	}
	ft_print_err(NOT_VALID_FILE);
	ft_exit_free(conf);
	return (0);
}
