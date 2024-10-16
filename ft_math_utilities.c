/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:09:07 by juan-pma          #+#    #+#             */
/*   Updated: 2023/12/03 11:11:09 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	ft_sum(t_complex complexz1, t_complex complexz2)
{
	t_complex	result;

	result.x = complexz1.x + complexz2.x;
	result.i = complexz1.i + complexz2.i;
	return (result);
}

double	fabs(double num)
{
	if (num < 0)
		return (-num);
	return (num);
}

t_complex	ft_abs(t_complex z, t_complex c)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.i * z.i) + (c.x);
	result.i = 2 * fabs(z.x * z.i) + c.i;
	return (result);
}

t_complex	square_num(t_complex z)
{
	t_complex	square;

	square.x = (z.x * z.x - z.i * z.i);
	square.i = (2 * z.x * z.i);
	return (square);
}

double	ft_linear_map(double val_scale, double t_pixel,
		double end_range, double start_range)
{
	return (start_range + ((val_scale - 0) / t_pixel)
		* (end_range - start_range));
}
