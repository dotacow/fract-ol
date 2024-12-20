/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:44:58 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/20 16:50:36 by dotacow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	lin_intrp(double transform, double l1, double l2, double res)
// linear interpolation, used to map pixel coordinates to complex plane
{
	return (transform * (l2 - l1) / (res) + l1);
}

t_cnum	c_sqrd(t_cnum c)
// square of a complex number
{
	t_cnum	ret;

	ret.x = c.x * c.x - c.y * c.y;
	ret.y = 2 * c.x * c.y;
	return (ret);
}

t_cnum	c_sum(t_cnum a, t_cnum b)
// sum of two complex numbers
{
	t_cnum	ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	return (ret);
}

double	c_mag(t_cnum c)
// magnitude of a complex number
{
	return (c.x * c.x + c.y * c.y);
}

double atodbl (char *s)
// absolute abomnation of a function
{
	long	i;
	double	f;
	double	pow;
	int		sign;

	i = 0;
	f = 0;
	sign = 1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		s++;
	while (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s != '.' && *s)
		i = (i * 10) + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s)
	{
		pow /= 10;
		f = f + (*s - '0') * pow;
		s++;
	}
	return ((double)(i + f) * sign);
}
