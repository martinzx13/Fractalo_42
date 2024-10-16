/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:38:57 by juan-pma          #+#    #+#             */
/*   Updated: 2023/12/03 10:45:09 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// We Need to parse the values, and check if the input
// is valid, for the 3 fractals that we will create.

// Mandelbrot
//		z(n+1) = z2 + c
// Julia <value 1> <value 2>
// 		z(n+1) = z2 + c 
//		check if the parse if valid.
//		c = (value1, value2)
// Burning Ship 
// 		z (n+1) = ∣xn − yn∣2 +c
// We will need to create some funcitons.
// math_functions ------- >
// square complex numbers.
// sum complex numbers.
// square single number.
// Fractal Render ----- >

#include "fractol.h"

static void	julia_init(t_fractol *fractal,
	double real, double i, char *name)
{
	fractal->frac_indi = 2;
	fractal->julia_x = real;
	fractal->julia_i = i;
	fractal->name = name;
}

void	data_init(t_fractol *fractal)
{
	fractal->limit = 4;
	fractal->iteration = 42;
	fractal->x_axis = 0.0;
	fractal->y_axis = 0.0;
	fractal->zoom = 1.0;
}

static void	fractal_engine(t_fractol *fractal)
{
	ft_fractal_init(fractal);
	ft_fractal_render(fractal);
	mlx_loop(fractal->mlx_ptr);
}

int	main(int argc, char *argv[])
{
	t_fractol	fractal;

	if (argc == 2 && (!ft_strcmp(argv[1], "mandelbrot", 10) 
			|| !ft_strcmp(argv[1], "burning ship", 12)))
	{
		fractal.name = argv[1];
		if (ft_strcmp(argv[1], "mandelbrot", 10))
			fractal.frac_indi = 1;
		else if (ft_strcmp(argv[1], "burning ship", 12))
			fractal.frac_indi = 3;
		fractal_engine(&fractal);
	}
	else if (argc == 4 && (!ft_strcmp(argv[1], "julia", 5)))
	{
		if (!ft_isnumeric(argv[2]) || !ft_isnumeric(argv[3]))
			ft_input_julia_error();
		else 
		{
			julia_init(&fractal, atodbl(argv[2]), atodbl(argv[3]), argv[1]);
			fractal_engine(&fractal);
		}
	}
	else
		ft_input_error();
	return (1);
}
