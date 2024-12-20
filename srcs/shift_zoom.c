/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:50:43 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/20 14:42:33 by dotacow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	shift_left(t_data *data)
{
	double	x_shift;

	x_shift = (data->xl2 - data->xl1);
	data->xl1 -= x_shift / (data->zoom);
	data->xl2 -= x_shift / (data->zoom);
}

void	shift_right(t_data *data)
{
	double	x_shift;

	x_shift = (data->xl2 - data->xl1);
	data->xl1 += x_shift / (data->zoom);
	data->xl2 += x_shift / (data->zoom);
}

void	shift_up(t_data *data)
{
	double	y_shift;

	y_shift = (data->yl1 - data->yl2);
	data->yl1 += y_shift / (data->zoom);
	data->yl2 += y_shift / (data->zoom);
}

void	shift_down(t_data *data)
{
	double	y_shift;

	y_shift = (data->yl1 - data->yl2);
	data->yl1 -= y_shift / (data->zoom);
	data->yl2 -= y_shift / (data->zoom);
}
