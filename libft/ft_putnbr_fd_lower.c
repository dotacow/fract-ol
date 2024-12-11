/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:19:06 by yokitane          #+#    #+#             */
/*   Updated: 2024/09/16 17:16:47 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_char(char c, int fd, int *count)
{
	write(fd, &c, 1);
	(*count)++;
}

static void	ft_putnbr_base(long long n, int fd, int base, int *count)
{
	char		c;
	const char	*digits = "0123456789abcdef";

	if (n < 0)
	{
		write_char('-', fd, count);
		if (base == 10)
			n = -n;
	}
	if (n >= base)
		ft_putnbr_base(n / base, fd, base, count);
	c = digits[n % base];
	write_char(c, fd, count);
}

int	ft_putnbr_fd_lower(long long nb, int fd, int base)
{
	int			count;
	long long	n;

	n = nb;
	count = 0;
	if (base < 2 || base > 16)
		return (-1);
	if (nb == 0)
	{
		write_char('0', fd, &count);
		return (count);
	}
	ft_putnbr_base(n, fd, base, &count);
	return (count);
}
