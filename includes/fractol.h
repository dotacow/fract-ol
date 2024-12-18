/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:30:31 by yokitane          #+#    #+#             */
/*   Updated: 2024/12/18 18:08:07 by dotacow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"

#define WIDTH 800
#define HEIGHT 800

typedef struct s_img
//image data
{
	void	*img;
	char	*addr;
	int		bbp;
	int		llen;
	int		endian;
}				t_img;

typedef struct s_cnum
{
	double	real;
	double	imaginary;
}				t_cnum;

enum e_fractal
{
	MANDELBROT,
	JULIA
};

typedef struct s_data
{
	int		fractal;
	void	*mlx;
	void	*win;
	t_img	imgd;
	int		offset_x;
	int		offset_y;

}				t_data;

/*functions*/
void	fractal_init(t_data *data);
void	malloc_fail(void);
void	fractal_render(t_data *data);
void	my_pixel_put(t_data *data, int x, int y, int color);
void	pixel_iter(t_data *data, int x, int y);
int		ARGB(int a, int r, int g, int b);

#endif
