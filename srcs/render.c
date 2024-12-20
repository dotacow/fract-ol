/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:23:51 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/20 13:27:42 by dotacow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// z = z^2 + c is the iteration formula
// in julia, c is constant
// in mandelbrot, z is constant(0)

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
{
	t_cnum	c;
	t_cnum	z;
	double	i;
	double	color;

	z.x = lin_intrp(x, data->xl1, data->xl2, WIDTH) * data->zoom;
	z.y = lin_intrp(y, data->yl2, data->yl1, HEIGHT) * data->zoom;
	pick_fractal(data, &c, &z);
	i = 0;
	while (i < data->iter_ceil)
	{
		z = c_sum(c_sqrd(z),c);
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
	int	x;
	int	y;

	printf("current iteration ceiling: %f\n", data->iter_ceil);
	printf("Current zoom: %f\n", data->zoom);
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
