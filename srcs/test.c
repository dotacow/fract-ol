/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dotacow <dotacow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:02:30 by dotacow           #+#    #+#             */
/*   Updated: 2024/12/15 20:33:46 by dotacow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../includes/fract-ol.h"

int main (void)
{
	void	*mlx;
	void	*mlx_win;

	ft_printf("test");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "for fucks sake work");
	mlx_loop(mlx);
}

