/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:50:43 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/22 18:12:28 by dotacow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	shift_x(t_data *data, int direction)
{
	double	x_shift;

	x_shift = (data->xl2 - data->xl1) / 2.5;
	if (direction == 1)
	{
		data->xl1 += x_shift;
		data->xl2 += x_shift;
	}
	else if (direction == -1)
	{
		data->xl1 -= x_shift;
		data->xl2 -= x_shift;
	}
}

void	shift_y(t_data *data, int direction)
{
	double	y_shift;

	y_shift = (data->yl1 - data->yl2) / 2.5;
	if (direction == 1)
	{
		data->yl1 += y_shift;
		data->yl2 += y_shift;
	}
	else if (direction == -1)
	{
		data->yl1 -= y_shift;
		data->yl2 -= y_shift;
	}
}

void	zoom_in(t_data *data, int x, int y)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = lin_intrp(x, data->xl1, data->xl2, WIDTH);
	mouse_y = lin_intrp(y, data->yl2, data->yl1, HEIGHT);
	data->zoom *= 1.5;
	data->xl1 = mouse_x - (mouse_x - data->xl1) / 1.5;
	data->xl2 = mouse_x + (data->xl2 - mouse_x) / 1.5;
	data->yl1 = mouse_y - (mouse_y - data->yl1) / 1.5;
	data->yl2 = mouse_y + (data->yl2 - mouse_y) / 1.5;
}

void	zoom_out(t_data *data, int x, int y)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = lin_intrp(x, data->xl1, data->xl2, WIDTH);
	mouse_y = lin_intrp(y, data->yl2, data->yl1, HEIGHT);
	data->zoom /= 1.5;
	data->xl1 = mouse_x - (mouse_x - data->xl1) * 1.5;
	data->xl2 = mouse_x + (data->xl2 - mouse_x) * 1.5;
	data->yl1 = mouse_y - (mouse_y - data->yl1) * 1.5;
	data->yl2 = mouse_y + (data->yl2 - mouse_y) * 1.5;
}
