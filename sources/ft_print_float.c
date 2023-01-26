/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:44:18 by mgama             #+#    #+#             */
/*   Updated: 2023/01/26 21:34:20 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_flags.h"

static size_t	ft_strlen_floating_part(const char *str)
{
	size_t	count;
	int		counting;

	count = 0;
	counting = 0;
	while (*str != '\0')
	{
		str++;
		if (counting)
			count++;
		if (*str == '.')
			counting = 1;
	}
	return (count);
}

static void	ft_print_in_float_spaces(char *d_i, double save_f,
	t_data *data, t_flags flags)
{
	if (save_f < 0 && flags.dot >= 0)
		ft_putchar_c('-', data);
	ft_putstrprec(d_i, ft_strlen(d_i), data);
	if (flags.dot >= 0)
		ft_print_max_width(flags.dot,
			(int)ft_strlen_floating_part(d_i) - 1, 1, data);
}

static void	ft_print_float_spaces(char *d_i, double save_f,
	t_data *data, t_flags flags)
{
	if (flags.minus == 1)
		ft_print_in_float_spaces(d_i, save_f, data, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(d_i))
		flags.dot = ft_strlen(d_i);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		ft_print_width(flags.width, 0, flags.zero, data);
	}
	else
		ft_print_width(flags.width, ft_strlen(d_i), flags.zero, data);
	if (flags.minus == 0)
		ft_print_in_float_spaces(d_i, save_f, data, flags);
}

static void	ft_print_float_flags(t_flags *flags, double *li, t_data *data)
{
	if (*li < 0 && (flags->dot >= 0 || flags->zero == 1))
	{
		if (flags->zero == 1 && flags->dot == -1)
			ft_putstrprec("-", 1, data);
		(*li) *= -1;
		flags->zero = 1;
		flags->width--;
	}
	else if (*li >= 0 && flags->plus == 1)
	{
		ft_putstrprec("+", 1, data);
		flags->width--;
	}
	else if (*li >= 0 && flags->blank == 1)
	{
		ft_putstrprec(" ", 1, data);
		flags->width--;
	}
}

void	ft_print_float(double i, t_data *data, t_flags flags)
{
	char	*d_i;
	double	li;
	int		max;

	li = i;
	max = 6;
	if (flags.dot == 0 && li == 0)
	{
		ft_print_width(flags.width, 0, 0, data);
		return ;
	}
	if (flags.dot >= 0)
		max = flags.dot;
	ft_print_float_flags(&flags, &li, data);
	d_i = ft_ftoa(li, max);
	if (!d_i)
		return ;
	ft_print_float_spaces(d_i, i, data, flags);
	free(d_i);
}
