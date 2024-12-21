/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:50:43 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/21 18:48:33 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	shift_left(t_data *data)
{
	double	x_shift;

	x_shift = (data->xl2 - data->xl1) / 2.5;
	data->xl1 -= x_shift;
	data->xl2 -= x_shift;
}

void	shift_right(t_data *data)
{
	double	x_shift;

	x_shift = (data->xl2 - data->xl1) / 2.5;
	data->xl1 += x_shift;
	data->xl2 += x_shift;
}

void	shift_up(t_data *data)
{
	double	y_shift;

	y_shift = (data->yl1 - data->yl2) / 2.5;
	data->yl1 += y_shift;
	data->yl2 += y_shift;
}

void	shift_down(t_data *data)
{
	double	y_shift;

	y_shift = (data->yl1 - data->yl2) / 2.5;
	data->yl1 -= y_shift;
	data->yl2 -= y_shift;
}
