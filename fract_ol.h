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
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define ERROR_MESSAGE \
	"Enter: ./fractol mandelbrot  or  ./fractol julia <value1> <value2>\n"

# define WIDTH	1000
# define HEIGHT	1000

# define BLACK		0x000000
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define MAGNETA	0xFF00FF
# define LIME		0xFF6600
# define PURPLE		0x660066
# define AQUA		0x33CCCC
# define PINK		0xFF66B2
# define BLUE_2		0x0066FF
# define RED_2		0xFF3300

typedef struct s_values
{
	double	x;
	double	y;
}		t_value;

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
	double	esc_value;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}		t_fractal;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	fractal_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);
double	map(double unscaled_num, double new_min,
			double new_max, double old_max);
double	atodbl(char *s);
t_value	sum(t_value z1, t_value z2);
t_value	square(t_value z);
int		key_handler(int keysym, t_fractal *fractal);
int		close_handler(t_fractal *fractal);
int		mouse_handler(int button, int x, int y, t_fractal *fractal);

#endif
