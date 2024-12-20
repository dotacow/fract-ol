/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:02:30 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/21 19:14:30 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//bonus tbd:
// dynamic zoom
// extra fractal
// better color shift
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
		fractal_init(&data, argv);
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
