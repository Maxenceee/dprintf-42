/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:08:39 by mgama             #+#    #+#             */
/*   Updated: 2023/01/26 22:13:16 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"
#include "../includes/ft_flags.h"

static void	ft_print_in_u_int_spaces(char *unsi_int,
	t_data *data, t_flags flags)
{
	if (flags.dot >= 0)
		ft_print_width(flags.dot - 1, ft_strlen(unsi_int) - 1, 1, data);
	ft_putstrprec(unsi_int, ft_strlen(unsi_int), data);
}

static void	ft_print_u_int_spaces(char *unsi_int,
	t_data *data, t_flags flags)
{
	if (flags.minus == 1)
		ft_print_in_u_int_spaces(unsi_int, data, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(unsi_int))
		flags.dot = ft_strlen(unsi_int);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		ft_print_width(flags.width, 0, 0, data);
	}
	else
		ft_print_width(flags.width,
			ft_strlen(unsi_int), flags.zero, data);
	if (flags.minus == 0)
		ft_print_in_u_int_spaces(unsi_int, data, flags);
}

void	ft_print_u_int(unsigned int unsi, t_data *data, t_flags flags)
{
	char	*unsi_int;

	unsi = (unsigned int)(4294967295 + 1
			+ unsi);
	if (flags.dot == 0 && unsi == 0)
	{
		ft_print_width(flags.width, 0, 0, data);
		return ;
	}
	unsi_int = ft_u_itoa(unsi);
	if (!unsi)
		return ;
	ft_print_u_int_spaces(unsi_int, data, flags);
	free(unsi_int);
}
