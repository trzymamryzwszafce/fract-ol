#include "fract_ol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connect, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connect, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connect);
	free(fractal->mlx_connect);
	exit(EXIT_SUCCESS);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = (map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	mouse_y = (map(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	if (button == Button4)
		fractal->zoom *= 0.9;
	else if (button == Button5)
		fractal->zoom *= 1.1;
	fractal->shift_x = mouse_x - (map(x, -2, 2, WIDTH) * fractal->zoom);
	fractal->shift_y = mouse_y - (map(y, 2, -2, HEIGHT) * fractal->zoom);
	mlx_clear_window(fractal->mlx_connect, fractal->mlx_window);
	fractal_render(fractal);
	return (0);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x -= (0.3 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.3 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.3 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.3 * fractal->zoom);
	else if (keysym == XK_period)
		fractal->iterations += 5;
	else if (keysym == XK_comma)
		fractal->iterations -= 5;
	mlx_clear_window(fractal->mlx_connect, fractal->mlx_window);
	fractal_render(fractal);
	return (0);
}
