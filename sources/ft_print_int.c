/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:17:43 by mgama             #+#    #+#             */
/*   Updated: 2023/01/26 22:13:16 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"
#include "../includes/ft_flags.h"

static void	ft_print_in_int_spaces(char *d_i, int save_i,
	t_data *data, t_flags flags)
{
	if (save_i < 0 && flags.plus == 0 && flags.dot >= 0)
		ft_putchar_c('-', data);
	if (flags.dot >= 0)
		ft_print_width(flags.dot - 1, ft_strlen(d_i) - 1, 1, data);
	ft_putstrprec(d_i, ft_strlen(d_i), data);
}

static void	ft_print_int_spaces(char *d_i, int save_i,
	t_data *data, t_flags flags)
{
	if (flags.minus == 1)
		ft_print_in_int_spaces(d_i, save_i, data, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(d_i))
		flags.dot = ft_strlen(d_i);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		ft_print_width(flags.width, 0, 0, data);
	}
	else
		ft_print_width(flags.width, ft_strlen(d_i), flags.zero, data);
	if (flags.minus == 0)
		ft_print_in_int_spaces(d_i, save_i, data, flags);
}

static void	ft_print_int_flags(t_flags *flags, long int *li, t_data *data)
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

void	ft_print_int(int i, t_data *data, t_flags flags)
{
	char		*d_i;
	long int	li;

	li = i;
	if (flags.dot == 0 && li == 0)
	{
		ft_print_width(flags.width, 0, 0, data);
		return ;
	}
	ft_print_int_flags(&flags, &li, data);
	d_i = ft_itoa(li);
	if (!d_i)
		return ;
	ft_print_int_spaces(d_i, i, data, flags);
	free(d_i);
}
