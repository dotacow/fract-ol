/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:55:31 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/18 20:51:25 by dotacow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void malloc_fail(void)
{
	perror("malloc failed");
	exit(EXIT_FAILURE);
}

static void data_init(t_data *data)
{
	data->offset_x = 0;
	data->offset_y = 0;
	data->zoom = 1;
	data->iter_ceil = 416;
	data->escape_val = 4;
	data->mlx = mlx_init();
	if (!data->mlx)
		malloc_fail();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		malloc_fail();
	}
}

void	fractal_init(t_data *data)
{
	data_init(data);
	data->imgd.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->imgd.img)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		malloc_fail();
	}
	data->imgd.addr = mlx_get_data_addr(data->imgd.img, &data->imgd.bpp,
		&data->imgd.llen, &data->imgd.endian);
	if (!data->imgd.addr)
	{
		mlx_destroy_image(data->mlx, data->imgd.img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		malloc_fail();
	}
	//events_init(data);
	//data_init(data);
}
