/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:30:31 by yokitane          #+#    #+#             */
/*   Updated: 2024/12/23 11:44:40 by dotacow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "colors.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 800
# define ITER_CEIL 556
# define ESCAPE_VAL 42
# define ZOOM 1.5

// image data
typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			llen;
	int			endian;
}				t_img;

typedef struct s_cnum
{
	double		x;
	double		y;
}				t_cnum;

enum			e_fractal
{
	MANDELBROT,
	JULIA,
	BEETLE
};

enum			e_pallet
{
	MAGMA,
	RAINBOW
};

typedef struct s_data
{
	int			fractal;
	int			pallet;
	void		*mlx;
	void		*win;
	t_img		imgd;
	double		iter_ceil;
	double		escape_val;
	double		xl1;
	double		xl2;
	double		yl1;
	double		yl2;
	t_cnum		z;
	double		sharpness;
}				t_data;
/*Initi and error handling*/
void			fractal_init(t_data *data, char **argv);
void			free_data(t_data *data);
/*rendering*/
void			fractal_render(t_data *data);
void			my_pixel_put(int x, int y, t_img *img, int color);
/* fractal types, iteritave and newton */
void			pixel_iter(t_data *data, int x, int y);
void			pixel_beetle(t_data *data, int x, int y);
/*color*/
unsigned int	interpolate_color(double t, unsigned int c1, unsigned int c2);
unsigned int	get_color(double t, t_data *data);
unsigned int	get_color_magma(double t);
unsigned int	get_color_rainbow(double t);
/*🤓*/
double			lin_intrp(double transform, double l1, double l2, double res);
double			atodbl(char *s);
/*events*/
void			my_hooks(t_data *data);
int				key_press(int keycode, t_data *data);
int				mouse_press(int button, int x, int y, t_data *data);
int				exit_hook(t_data *data);
/* shift and zoom */
void			zoom_in(t_data *data, int x, int y);
void			zoom_out(t_data *data, int x, int y);
void			shift_x(t_data *data, int direction);
void			shift_y(t_data *data, int direction);

#endif
