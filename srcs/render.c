/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:23:51 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/18 18:08:49 by dotacow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	pixel_iter(t_data *data, int x, int y)
{
	
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	data->offset_x = x * (data->imgd.bbp / 8);
	data->offset_y = y * data->imgd.llen;
	dst = data->imgd.addr + data->offset_x + data->offset_y;
	*(unsigned int *)dst = color;
}

void	fractal_render(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pixel_iter(data, x, y);
			x++;
		}
		y++;
	}
}