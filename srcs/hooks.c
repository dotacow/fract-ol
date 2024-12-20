/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:15:36 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/20 13:41:06 by dotacow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_hooks(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->win, ButtonPress, ButtonPressMask, mouse_press, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, exit_hook, data);
	/* mlx_hook(data->win, MotionNotify, PointerMotionMask, mouse_move, data); */
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
		data->iter_ceil += 5;
	else if (keycode == XK_minus)
		data->iter_ceil -= 5;
	fractal_render(data);
	return (0);
}

int	mouse_press(int button, int x, int y, t_data *data)
{
	(void)(x+ y);
	if (button == 5)
		data->zoom *= 1.5;
	else if (button == 4)
		data->zoom /= 1.5;
	fractal_render(data);
	return (0);
}

int	exit_hook(t_data *data)
{
	free_data(data);
	return (0);
}
/*
int	mouse_move(int x, int y, t_data *data)
{
	(void)(x+y);
	if (data->fractal == JULIA)
	{
		data->z.x = lin_intrp(x, data->xl1, data->xl2, WIDTH) * data->zoom;
		data->z.y = lin_intrp(y, data->yl2, data->yl1, HEIGHT) * data->zoom;
		fractal_render(data);
	}
	return (0);
} */
