/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:55:31 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/18 17:31:38 by dotacow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void malloc_fail(void)
{
	perror("malloc failed");
	exit(EXIT_FAILURE);
}

void	fractal_init(t_data *data)
{
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
	data->imgd.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->imgd.img)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		malloc_fail();
	}
	data->imgd.addr = mlx_get_data_addr(data->imgd.img, &data->imgd.bbp,
		&data->imgd.llen, &data->imgd.endian);
	//events_init(data);
	//data_init(data);
}
