/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:23:51 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/22 21:04:23 by dotacow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	void	pick_fractal(t_data *data, t_cnum *c, t_cnum *z)
{
	if (data->fractal == MANDELBROT)
	{
		c->x = z->x;
		c->y = z->y;
	}
	else if (data->fractal == JULIA)
	{
		c->x = data->z.x;
		c->y = data->z.y;
	}
}

void	pixel_iter(t_data *data, int x, int y)
/* this function is used to render iteritave fractals,
 i.e julia and mandelbrot */
{
	t_cnum	c;
	t_cnum	z;
	double	i;
	double	temp_x;

	z.x = lin_intrp(x, data->xl1, data->xl2, WIDTH);
	z.y = lin_intrp(y, data->yl2, data->yl1, HEIGHT);
	c.x = 0;
	c.y = 0;
	pick_fractal(data, &c, &z);
	i = 0;
	while (i < data->iter_ceil)
	{
		temp_x = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp_x;
		if ((z.x * z.x + z.y * z.y) > data->escape_val * data->escape_val)
		{
			my_pixel_put(x, y, &data->imgd,
					get_color(i / data->iter_ceil, data));
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &data->imgd, BLACK);
}

void	pixel_newton(t_data *data, int x, int y)
/* TBD!!!!! */
{
	t_cnum	z;
	t_cnum	z_next;
	double	i;
	double	temp_x;
	double	temp_y;
	double	denom;

	z.x = lin_intrp(x, data->xl1, data->xl2, WIDTH);
	z.y = lin_intrp(y, data->yl2, data->yl1, HEIGHT);
	i = 0;
	while (i < data->iter_ceil)
	{
		denom = 3 * (z.x * z.x + z.y * z.y) * (z.x * z.x + z.y * z.y);
		if (denom == 0)
			break;
		temp_x = (2 * z.x * (z.x * z.x - 3 * z.y * z.y)) / denom + z.x / 3;
		temp_y = (2 * z.y * (3 * z.x * z.x - z.y * z.y)) / denom + z.y / 3;
		z_next.x = temp_x;
		z_next.y = temp_y;
		if ((z_next.x - z.x) * (z_next.x - z.x) + (z_next.y - z.y) * (z_next.y - z.y) < 1e-6)
			break;
		z.x = z_next.x;
		z.y = z_next.y;
		i++;
	}
	my_pixel_put(x, y, &data->imgd, get_color_magma(i / data->iter_ceil));
}

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->llen) + (x * (img->bpp / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

void	fractal_render(t_data *data)
{
	int	x;
	int	y;

	printf("current iteration ceiling: %f\n", data->iter_ceil);
	y = -1;
	if (data->fractal == MANDELBROT || data->fractal == JULIA)
	{
		while (++y < HEIGHT)
		{
			x = -1;
			while (++x < WIDTH)
			{
				pixel_iter(data, x, y);
			}
		}
	}
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pixel_newton(data, x, y);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->imgd.img, 0, 0);
}
