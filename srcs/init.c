/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:55:31 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/19 15:17:51 by dotacow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	data_init(t_data *data)
{
	data->zoom = 1;
	data->iter_ceil = 252;
	data->escape_val = 4;
	data->xl1 = -2;
	data->xl2 = 2;
	data->yl1 = 2;
	data->yl2 = -2;
}

void	fractal_init(t_data *data)
{
	data_init(data);
	data->mlx = mlx_init();
	if (!data->mlx)
		free_data(data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!data->win)
		free_data(data);
	data->imgd.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->imgd.img)
		free_data(data);
	data->imgd.addr = mlx_get_data_addr(data->imgd.img, &data->imgd.bpp,
			&data->imgd.llen, &data->imgd.endian);
	if (!data->imgd.addr)
		free_data(data);
	my_hooks(data);
}
