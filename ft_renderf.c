/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:34:27 by juan-pma          #+#    #+#             */
/*   Updated: 2023/12/03 11:47:40 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bite_pp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

static void	fractal_equation(t_fractol *fractal, t_complex *c, t_complex *z)
{
	if (fractal->frac_indi == 2)
	{
		c->i = fractal->julia_i;
		c->x = fractal->julia_x;
	}
	else
	{
		c->x = z->x;
		c->i = z->i;
	}
}

void	events_init(t_fractol *fractal)
{
	mlx_hook(fractal->mlx_win_ptr, 
		04,
		1L << 2,
		mouse_handle,
		fractal);
	mlx_hook(fractal->mlx_win_ptr, 
		2,
		1L << 0,
		key_board_handle,
		fractal);
	mlx_hook(fractal->mlx_win_ptr,
		17,
		1L << 17,
		close_handle,
		fractal);
}

void	handle_pixel(int x, int y, t_fractol *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (ft_linear_map(x, WITDHT, +2, -2) * fractal->zoom) + fractal->x_axis;
	z.i = (ft_linear_map(y, HEIGHT, +2, -2) * fractal->zoom) + fractal->y_axis;
	fractal_equation(fractal, &c, &z);
	while (i++ < fractal->iteration)
	{
		if (fractal->frac_indi == 1)
			z = ft_abs(z, c);
		else 
			z = ft_sum(square_num(z), c);
		if ((z.x * z.x) + (z.i * z.i) > fractal->limit)
		{
			color = ft_linear_map(i, fractal->iteration, WHITE, BLACK);
			my_pixel_put(x, y, &fractal->image, color);
			return ;
		}
	}
	my_pixel_put(x, y, &fractal->image, BLACK);
}

void	ft_fractal_render(t_fractol *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WITDHT)
			handle_pixel(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_ptr,
		fractal->mlx_win_ptr,
		fractal->image.img_ptr, 0, 0);
}
