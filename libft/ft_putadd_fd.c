/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:19:08 by yokitane          #+#    #+#             */
/*   Updated: 2024/09/16 17:25:10 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_char(char c, int fd, int *count)
{
	write(fd, &c, 1);
	(*count)++;
}

static void	ft_putnbr_base(unsigned long n, int fd, unsigned long base,
		int *count)
{
	char		c;
	const char	*digits = "0123456789abcdef";

	if (n >= base)
		ft_putnbr_base(n / base, fd, base, count);
	c = digits[n % base];
	write_char(c, fd, count);
}

int	ft_putadd_fd(unsigned long nb, int fd, unsigned long base)
{
	int			count;
	long long	n;

	n = nb;
	count = 0;
	if (base < 2 || base > 16)
		return (-1);
	if (nb == 0)
	{
		count += ft_putstr_fd("(nil)", 1);
		return (count);
	}
	count += ft_putstr_fd("0x", 1);
	ft_putnbr_base(n, fd, base, &count);
	return (count);
}
