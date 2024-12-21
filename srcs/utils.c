/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:54:36 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/21 13:40:49 by dotacow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	free_data(t_data *data)
{
	if (data->imgd.img)
		mlx_destroy_image(data->mlx, data->imgd.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	if (errno && errno != 11)
	{
		perror("something bad happened. have fun debugging (p");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

unsigned int	interpolate_color(double t, unsigned int c1, unsigned int c2)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = (unsigned int)(((1 - t)
				* ((c1 >> 16) & 0xFF)) + (t * ((c2 >> 16) & 0xFF)));
	g = (unsigned int)(((1 - t)
				* ((c1 >> 8) & 0xFF)) + (t * ((c2 >> 8) & 0xFF)));
	b = (unsigned int)(((1 - t)
				* (c1 & 0xFF)) + (t * (c2 & 0xFF)));
	return ((r << 16) | (g << 8) | b);
}

unsigned int	get_color(double t)
{
	int					cindex;
	int					idx1;
	int					idx2;
	double				pixel;
	const unsigned int	colors[] = {RED, LIME, YELLOW, GREEN, BLUE, TURQ,
		MAGENTA, ORANGE, PURPLE, PINK, DARK_BLUE, DARK_RED, DARK_GREEN,
		DARK_YELLOW, DARK_MAGENTA, DARK_ORANGE,
		DARK_PURPLE, DARK_TURQ, DARK_PINK
	};

	cindex = sizeof(colors) / sizeof(colors[0]);
	idx1 = (int)(t * (cindex - 1));
	idx2 = idx1 + 1;
	if (idx2 >= cindex)
		idx2 = cindex - 1;
	pixel = (t * (cindex - 1)) - idx1;
	return (interpolate_color(pixel, colors[idx1], colors[idx1 + idx2]));
}
