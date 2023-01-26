/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprint_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:55:31 by mgama             #+#    #+#             */
/*   Updated: 2023/01/26 22:22:31 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"
#include "../includes/ft_flags.h"

void	ft_dputchar_c(char c, t_data *data)
{
	write(data->fd, &c, 1);
	(data->count)++;
}

void	ft_dprint_char(char c, t_data *data, t_flags flags)
{
	if (flags.minus == 1)
		ft_dputchar_c(c, data);
	ft_dprint_width(flags.width, 1, 0, data);
	if (flags.minus == 0)
		ft_dputchar_c(c, data);
}
