/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:19:44 by juan-pma          #+#    #+#             */
/*   Updated: 2023/12/03 12:28:34 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <X11/keysym.h>
# include "mlx_linux/mlx.h"

# define MALLOCERROR "Error with malloc"
# define ERROR_MESSAGE1 
# define WITDHT 800
# define HEIGHT 800

// Define colors using hexadecimal RGB values
# define BLACK       0x000000
# define WHITE       0xFFFFFF

// Additional colors in hexadecimal
# define ORANGE      0xFFA500   // Daltonic-friendly orange
# define LIME_GREEN  0x32CD32   // Bright green
# define TURQUOISE   0x40E0D0   // Cyan-like color

// Structure of the code that I need. 
typedef struct s_num
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;
}	t_num;

// Structure of the Number.
typedef struct s_complex
{
	double	x;
	double	i;
}	t_complex;

// Structure of the image. 

typedef struct s_image
{
	void	*img_ptr;
	void	*pixel_ptr;
	int		bite_pp;
	int		endian;
	int		line_len;
}	t_image;

// Structure of the fractol
typedef struct s_fractol
{
	void	*mlx_ptr;
	void	*mlx_win_ptr;
	char	*name;
	int		frac_indi;
	double	julia_i;
	double	julia_x;
	int		limit;
	t_image	image;
	double	x_axis;
	double	y_axis;
	int		iteration;
	double	zoom;
}	t_fractol;

// Error management.
void		ft_input_julia_error(void);
void		ft_input_error(void);
// fractal utilities. 
void		ft_fractal_init(t_fractol *fractal); 
void		data_init(t_fractol *fractal);
void		ft_putstr(char *s);

// Math Utilities 
t_complex	ft_abs(t_complex z, t_complex c);
double		fabs(double num);
t_complex	ft_sum(t_complex complexz1, t_complex complexz2);
t_complex	square_num(t_complex z);
double		ft_linear_map(double pixel_position, double total_pixel,
				double end_range, double start_range);
// Libft Utilities 
int			ft_strcmp(char *s1, char *s2, int len);
void		ft_putstr(char *s);
void		ft_fractal_render(t_fractol *fractal);
int			ft_isnumeric(char *str);
int			ft_isdigit(int c);

/// event handler.
void		events_init(t_fractol *fractal);
int			mouse_handle(int button, int x, int y, t_fractol *fractal);
int			key_board_handle(int keysym, t_fractol *fractal);
int			close_handle(t_fractol *fractal);
double		atodbl(char *s);

#endif
