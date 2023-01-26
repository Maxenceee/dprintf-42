/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprint_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:47:22 by mgama             #+#    #+#             */
/*   Updated: 2023/01/26 22:12:17 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"
#include "../includes/ft_flags.h"

static void	ft_dprint_in_pointer_spaces(char *pointer,
	t_data *data, t_flags flags)
{
	ft_putstrprec("0x", 2, data);
	if (flags.dot >= 0)
	{
		ft_dprint_width(flags.dot, ft_strlen(pointer), 1, data);
		ft_putstrprec(pointer, flags.dot, data);
	}
	else
		ft_putstrprec(pointer, ft_strlen(pointer), data);
}

void	ft_dprint_pointer(unsigned long long ull,
	t_data *data, t_flags flags)
{
	char	*pointer;

	if (ull == 0 && flags.dot == 0)
	{
		ft_putstrprec("0x", 2, data);
		ft_dprint_width(flags.width, 0, 1, data);
		return ;
	}
	pointer = ft_convert_base(ull, 16);
	if (!pointer)
		return ;
	pointer = ft_str_tolower(pointer);
	if ((size_t)flags.dot < ft_strlen(pointer))
		flags.dot = ft_strlen(pointer);
	if (flags.minus == 1)
		ft_dprint_in_pointer_spaces(pointer, data, flags);
	ft_dprint_width(flags.width, ft_strlen(pointer) + 2, 0, data);
	if (flags.minus == 0)
		ft_dprint_in_pointer_spaces(pointer, data, flags);
	free(pointer);
}
