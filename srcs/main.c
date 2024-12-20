/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:02:30 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/20 12:43:24 by dotacow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || (argc == 4
			&& !ft_strncmp(argv[1], "julia", 5)))
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 10))
			data.fractal = MANDELBROT;
		else
			data.fractal = JULIA;
		fractal_init(&data,argv);
		ft_printf("julia.x: %f\n", data.z.x);
		ft_printf("julia.y: %f\n", data.z.y);
		fractal_render(&data);
		mlx_loop(data.mlx);
	}
	else
	{
		errno = EINVAL;
		perror("Usage: ./fractol mandelbrot");
		perror("fractol julia [real] [imaginary]");
		exit(EXIT_FAILURE);
	}
}
