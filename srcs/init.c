/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:55:31 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/23 11:48:02 by dotacow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	data_init(t_data *data, char **argv)
{
	data->iter_ceil = ITER_CEIL;
	data->escape_val = ESCAPE_VAL;
	data->xl1 = -2.00;
	data->xl2 = 2.00;
	data->yl1 = 2.00;
	data->yl2 = -2.00;
	data->z.x = 0.00;
	data->z.y = 0.00;
	if (data->fractal == JULIA)
	{
		data->z.x = atodbl(argv[2]);
		data->z.y = atodbl(argv[3]);
	}
	data->pallet = RAINBOW;
	data->sharpness = 256;
}

void	fractal_init(t_data *data, char **argv)
{
	data_init(data, argv);
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
