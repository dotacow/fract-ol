/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:54:36 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/19 15:03:52 by dotacow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void free_data(t_data *data)
{
	if (data->imgd.img)
		mlx_destroy_image(data->mlx, data->imgd.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	if (errno && errno != 11 )
	{
		perror("something bad happened. have fun debugging (p");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
