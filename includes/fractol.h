/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:30:31 by yokitane          #+#    #+#             */
/*   Updated: 2024/12/18 20:29:53 by dotacow          ###   ########.fr       */
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
# include "colors.h"

#define WIDTH 800
#define HEIGHT 800

typedef struct s_img
//image data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llen;
	int		endian;
}				t_img;

typedef struct s_cnum
{
	double	x;
	double	y;
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
	double	zoom;
	int		iter_ceil;
	double	escape_val;

}				t_data;

/*Initi and error handling*/
void	fractal_init(t_data *data);
void	malloc_fail(void);
/*rendering*/
void	fractal_render(t_data *data);
void	my_pixel_put(int x, int y, t_img *img, int color);
void	pixel_iter(t_data *data, int x, int y);
/*color*/
int		ARGB(int a, int r, int g, int b);
/*🤓*/
double	lin_intrp(double transform, double l1, double l2, double res);
t_cnum	c_sqrd(t_cnum c);
t_cnum	c_sum(t_cnum a, t_cnum b);
double	c_mag(t_cnum c);

#endif
