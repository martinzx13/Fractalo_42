/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errormsg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:09:17 by juan-pma          #+#    #+#             */
/*   Updated: 2023/12/09 11:09:46 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_input_julia_error(void)
{
	ft_putstr("Please enter a valid value :\"./fractol \"julia\" \n\t");
	ft_putstr("\" \"-0.8\" \"1.25\" \n\t");
	ft_putstr("\" \"-0.123\" \"-0.25\" \n\t");
	ft_putstr("\" \"-1.0\" \"0.0\" \n\t");
	exit(EXIT_FAILURE);
}

void	ft_input_error(void)
{
	ft_putstr("Please enter a valid Input : \n\t\"./fractol \"mandelbrot\" \n\t");
	ft_putstr("\"./fractol \"burning ship\" \n\t");
	ft_putstr("\"./fractol \"julia\" \"value 1\" \"value 2\" \n");
}
