/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:19:02 by juan-pma          #+#    #+#             */
/*   Updated: 2023/12/03 11:19:53 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2, int len)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*s1 == *s2 && len > 0 && *s1)
	{
		s1++;
		s2++;
		len--;
	}
	return (*s1 - *s2);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isnumeric(char *str)
{
	int				dot_track;

	dot_track = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str == '.')
		{
			if (dot_track)
				return (0);
			dot_track = 1;
		}
		else if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	if (dot_track && str[-1] == '.')
		return (0);
	return (1);
}

double	atodbl(char *s)
{
	t_num	num;

	num.integer_part = 0;
	num.fractional_part = 0;
	num.sign = +1;
	num.pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	if ('+' == *s || '-' == *s)
	{
		if ('-' == *s++)
			num.sign = -num.sign;
	}
	while (*s != '.' && *s)
		num.integer_part = (num.integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		num.pow /= 10;
		num.fractional_part = num.fractional_part + (*s++ - 48) * num.pow;
	}
	return ((num.integer_part + num.fractional_part) * num.sign);
}
