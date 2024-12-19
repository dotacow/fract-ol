/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:44:58 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/19 17:13:05 by yokitane         ###   ########.fr       */
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
