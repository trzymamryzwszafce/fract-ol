/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szmadeja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:51:47 by szmadeja          #+#    #+#             */
/*   Updated: 2025/04/16 19:34:24 by szmadeja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx.h"
# include "./libft/libft.h"
# include <unistd.h> 
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define ERROR_MESSAGE \
	"Enter:./fractol mandelbrot  or  ./fractol julia <value1> <value2>\n"

# define WIDTH	800
# define HEIGHT	800

typedef struct s_img
{
	void	*img_ptr;
	char	*pxl_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connect;
	void	*mlx_window;
	t_img	img;
}		t_fractal;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

#endif
