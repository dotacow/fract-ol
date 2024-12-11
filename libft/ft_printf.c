/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:17:19 by yokitane          #+#    #+#             */
/*   Updated: 2024/09/16 17:41:40 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_arghand(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (format == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (format == 'p')
		return (ft_putadd_fd(va_arg(args, unsigned long), 1, 16));
	else if (format == 'd')
		return (ft_putnbr_fd(va_arg(args, int), 1, 10));
	else if (format == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1, 10));
	else if (format == 'u')
		return (ft_putnbr_fd(va_arg(args, unsigned int), 1, 10));
	else if (format == 'x')
		return (ft_putnbr_fd_lower(va_arg(args, unsigned int), 1, 16));
	else if (format == 'X')
		return (ft_putnbr_fd(va_arg(args, unsigned int), 1, 16));
	else if (format == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			count += ft_arghand(format[++i], args);
		else
			count += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
