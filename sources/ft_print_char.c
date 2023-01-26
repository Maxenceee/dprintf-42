/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:55:31 by mgama             #+#    #+#             */
/*   Updated: 2023/01/26 22:13:16 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"
#include "../includes/ft_flags.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_c(char c, t_data *data)
{
	write(data->fd, &c, 1);
	(data->count)++;
}

void	ft_print_char(char c, t_data *data, t_flags flags)
{
	if (flags.minus == 1)
		ft_putchar_c(c, data);
	ft_print_width(flags.width, 1, 0, data);
	if (flags.minus == 0)
		ft_putchar_c(c, data);
}
