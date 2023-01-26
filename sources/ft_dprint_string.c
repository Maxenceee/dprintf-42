/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprint_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:07:51 by mgama             #+#    #+#             */
/*   Updated: 2023/01/26 22:13:16 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"
#include "../includes/ft_flags.h"

void	ft_putstrprec(char *str, int prec, t_data *data)
{
	int	c;

	c = 0;
	while (str[c] && c < prec)
		ft_putchar(str[c++]);
	(data->count) += c;
}

static void	ft_dprint_spaces(char *str, t_data *data, t_flags flags)
{
	if (flags.dot >= 0)
	{
		ft_dprint_width(flags.dot, ft_strlen(str), 0, data);
		ft_putstrprec(str, flags.dot, data);
	}
	else
	{
		ft_putstrprec(str, ft_strlen(str), data);
	}
}

void	ft_dprint_str(char *s, t_data *data, t_flags flags)
{
	int	c;

	c = 0;
	if (!s)
		s = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(s))
		flags.dot = ft_strlen(s);
	if (flags.minus == 1)
		ft_dprint_spaces(s, data, flags);
	if (flags.dot >= 0)
		ft_dprint_max_width(flags.width, flags.dot, 0, data);
	else
		ft_dprint_width(flags.width, ft_strlen(s), 0, data);
	if (flags.minus == 0)
		ft_dprint_spaces(s, data, flags);
	(data->count) += c;
}
