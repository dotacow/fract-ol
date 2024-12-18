/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:23:51 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/18 20:46:06 by dotacow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// z = z^2 + c is the iteration formula
// in julia, c is constant
// in mandelbrot, c is the pixel
void	pixel_iter(t_data *data, int x, int y)
{
	t_cnum	z;
	t_cnum	c;
	int		i;
	int		color;

	z.x = 0;
	z.y = 0;
	c.x = lin_intrp(x, -2,+2, WIDTH);
	c.y = lin_intrp(y, +2,-2, HEIGHT);
	i = 0;
	while (i < data->iter_ceil)
	{
		z = c_sum(c_sqrd(z), c);
		if (c_mag(z) > data->escape_val)
		{
			color = lin_intrp(i, BLACK, WHITE, data->iter_ceil);
			my_pixel_put(x, y, &data->imgd, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &data->imgd, BLACK);
}

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->llen) + (x * (img->bpp / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

void	fractal_render(t_data *data)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pixel_iter(data, x, y);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->imgd.img, 0, 0);
}
