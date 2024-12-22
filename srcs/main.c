/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:02:30 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/22 21:53:56 by dotacow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//bonus tbd:
// extra fractal
int	main(int argc, char **argv)
{
	t_data	data;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || (argc == 4
			&& !ft_strncmp(argv[1], "julia", 5))
		|| (argc == 2 && !ft_strncmp(argv[1], "beetle", 6)))
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 10))
			data.fractal = MANDELBROT;
		else if (!ft_strncmp(argv[1], "julia", 5))
			data.fractal = JULIA;
		else
			data.fractal = BEETLE;
		fractal_init(&data, argv);
		fractal_render(&data);
		mlx_loop(data.mlx);
	}
	else
	{
		errno = EINVAL;
		perror("Usage: ./fractol beetle-mandelbrot-julia <real> <imaginary>");
		exit(EXIT_FAILURE);
	}
}
