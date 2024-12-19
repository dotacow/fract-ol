/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:50:43 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/19 15:15:03 by dotacow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	shift_left(t_data *data)
{
	double	x_shift;

	x_shift = (data->xl2 - data->xl1) / data->zoom / 10;
	data->xl1 -= x_shift;
	data->xl2 -= x_shift;
}

void	shift_right(t_data *data)
{
	double	x_shift;

	x_shift = (data->xl2 - data->xl1) / data->zoom / 10;
	data->xl1 += x_shift;
	data->xl2 += x_shift;
}

void	shift_up(t_data *data)
{
	double	y_shift;

	y_shift = (data->yl1 - data->yl2) / data->zoom / 10;
	data->yl1 += y_shift;
	data->yl2 += y_shift;
}

void	shift_down(t_data *data)
{
	double	y_shift;

	y_shift = (data->yl1 - data->yl2) / data->zoom / 10;
	data->yl1 -= y_shift;
	data->yl2 -= y_shift;
}