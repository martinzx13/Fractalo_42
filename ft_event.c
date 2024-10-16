/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:14:09 by juan-pma          #+#    #+#             */
/*   Updated: 2023/12/03 12:15:53 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_handle(int button, int x, int y, t_fractol *fractal)
{
	if (button == 5 && x)
		fractal->zoom *= 1.05;
	else if (button == 4 && y)
		fractal->zoom *= 0.95;
	ft_fractal_render(fractal);
	return (button);
}

int	key_board_handle(int keysym, t_fractol *fractal)
{
	if (keysym == XK_Escape)
		close_handle(fractal);
	else if (keysym == XK_Up || keysym == XK_w)
		fractal->y_axis -= 0.5 * fractal->zoom;
	else if (keysym == XK_Down || keysym == XK_s)
		fractal->y_axis += 0.5 * fractal->zoom;
	else if (keysym == XK_Right || keysym == XK_d)
		fractal->x_axis += 0.5 * fractal->zoom;
	else if (keysym == XK_Left || keysym == XK_a)
		fractal->x_axis -= 0.5 * fractal->zoom;
	else if (keysym == XK_minus)
		fractal->iteration -= 10;
	else if (keysym == XK_z)
		fractal->iteration += 10;
	ft_fractal_render(fractal);
	return (0);
}

int	close_handle(t_fractol *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->image.img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_win_ptr);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	exit(EXIT_SUCCESS);
}
