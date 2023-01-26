/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:33:24 by mgama             #+#    #+#             */
/*   Updated: 2023/01/26 22:09:35 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_flags.h"
#include "../includes/ft_printf.h"

static t_flags	ft_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	flags.plus = 0;
	flags.hex = 0;
	flags.blank = 0;
	return (flags);
}

static void	ft_switch_types(int type, va_list *argp,
	t_data *data, t_flags flags)
{
	if (type == '%')
		ft_putchar_c('%', data);
	else if (type == 'c')
		ft_print_char(va_arg(*argp, long), data, flags);
	else if (type == 's')
		ft_print_str(va_arg(*argp, char *), data, flags);
	else if (type == 'd' || type == 'i')
		ft_print_int(va_arg(*argp, long), data, flags);
	else if (type == 'f')
		ft_print_float(va_arg(*argp, double), data, flags);
	else if (type == 'u')
		ft_print_u_int(va_arg(*argp, unsigned long), data, flags);
	else if (type == 'x')
		ft_print_hex(va_arg(*argp, unsigned int), 1, data, flags);
	else if (type == 'X')
		ft_print_hex(va_arg(*argp, unsigned int), 0, data, flags);
	else if (type == 'p')
		ft_print_pointer(va_arg(*argp, unsigned long int), data, flags);
}

static void	ft_print_type(const char *fmt, va_list *argp, t_data *data)
{
	int		i;
	t_flags	flags;

	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] != '%')
		{
			ft_putchar_c(fmt[i++], data);
			continue ;
		}
		flags = ft_flags();
		i++;
		ft_check_flags(fmt, argp, &flags, &i);
		if (ft_is_valid_type(fmt[i]))
			ft_switch_types(flags.type, argp, data, flags);
		else
			ft_putchar_c(fmt[i], data);
		i++;
	}
}

int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	listp;
	t_data	data;

	if (fcntl(fd, F_GETFD) < 0)
		return (-1);
	data.count = 0;
	data.fd = fd;
	va_start(listp, fmt);
	ft_print_type(fmt, &listp, &data);
	va_end(listp);
	return (data.count);
}
