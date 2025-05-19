/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szmadeja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:41:57 by szmadeja          #+#    #+#             */
/*   Updated: 2025/05/19 18:41:59 by szmadeja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num) / old_max + new_min);
}

double	atodbl(char *s)
{
	long	i;
	double	f;
	double	pow;
	int		sign;

	i = 0;
	f = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		s++;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		i = (i * 10) + (*s++ - 48);
	if ('.' == *s)
		s++;
	while (*s)
	{
		pow /= 10;
		f = f + (*s++ - 48) * pow;
	}
	return ((i + f) * sign);
}

t_value	sum(t_value z1, t_value z2)
{
	t_value	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_value	square(t_value z)
{
	t_value	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}
