/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:02:14 by juan-pma          #+#    #+#             */
/*   Updated: 2023/12/03 12:05:17 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

void	ft_fractal_init(t_fractol *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		ft_malloc_error();
	fractal->mlx_win_ptr = mlx_new_window(fractal->mlx_ptr, WITDHT,
			HEIGHT, fractal->name);
	if (!fractal->mlx_win_ptr)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		ft_malloc_error();
	}
	fractal->image.img_ptr = mlx_new_image(fractal->mlx_ptr, WITDHT, HEIGHT);
	if (!fractal->image.img_ptr)
	{
		mlx_clear_window(fractal->mlx_ptr, fractal->mlx_win_ptr);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		ft_malloc_error();
	}
	fractal->image.pixel_ptr = mlx_get_data_addr(fractal->image.img_ptr, 
			&fractal->image.bite_pp,
			&fractal->image.line_len,
			&fractal->image.endian);
	events_init(fractal);
	data_init(fractal);
}
