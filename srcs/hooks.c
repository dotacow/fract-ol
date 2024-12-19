/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:15:36 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/19 19:24:28 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_hooks(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->win, ButtonPress, ButtonPressMask, mouse_press, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, exit_hook, data);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		free_data(data);
	else if (keycode == XK_Right)
		shift_left(data);
	else if (keycode == XK_Left)
		shift_right(data);
	else if (keycode == XK_Up)
		shift_up(data);
	else if (keycode == XK_Down)
		shift_down(data);
	else if (keycode == XK_plus || keycode == XK_equal)
		data->iter_ceil += 10;
	else if (keycode == XK_minus)
		data->iter_ceil -= 10;
	fractal_render(data);
	ft_printf("current iteration ceiling: %d\n", data->iter_ceil);
	return (0);
}

int	mouse_press(int button, int x, int y, t_data *data)
{
	(void)(x+ y);
	if (button == 4)
		data->zoom *= 1.1;
	else if (button == 5)
		data->zoom /= 1.1;
	return (0);
}

int	exit_hook(t_data *data)
{
	free_data(data);
	return (0);
}
