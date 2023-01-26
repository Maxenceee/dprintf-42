/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:26:50 by mgama             #+#    #+#             */
/*   Updated: 2023/01/26 22:13:16 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"
#include "../includes/ft_flags.h"

static void	ft_print_in_hex_spaces(char *hexa, int lower,
	t_data *data, t_flags flags)
{
	if (flags.hex == 1)
	{
		if (lower == 1)
			ft_putstrprec("0x", 2, data);
		else
			ft_putstrprec("0X", 2, data);
	}
	if (flags.dot >= 0)
		ft_print_width(flags.dot - 1, ft_strlen(hexa) - 1, 1, data);
	ft_putstrprec(hexa, ft_strlen(hexa), data);
}

static void	ft_print_hex_spaces(char *hexa, int lower,
	t_data *data, t_flags flags)
{
	if (flags.minus == 1)
		ft_print_in_hex_spaces(hexa, lower, data, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hexa))
		flags.dot = ft_strlen(hexa);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		ft_print_width(flags.width, 0, 0, data);
	}
	else
		ft_print_width(flags.width,
			ft_strlen(hexa), flags.zero, data);
	if (flags.minus == 0)
		ft_print_in_hex_spaces(hexa, lower, data, flags);
}

void	ft_print_hex(unsigned int ui, int lower, t_data *data, t_flags flags)
{
	char	*hexa;

	ui = (unsigned int)(4294967295 + 1
			+ ui);
	if (flags.dot == 0 && ui == 0)
	{
		ft_print_width(flags.width, 0, 0, data);
		return ;
	}
	if (ui == 0)
		flags.hex = 0;
	hexa = ft_convert_base((unsigned long long)ui, 16);
	if (!hexa)
		return ;
	if (lower == 1)
		hexa = ft_str_tolower(hexa);
	ft_print_hex_spaces(hexa, lower, data, flags);
	free(hexa);
}
