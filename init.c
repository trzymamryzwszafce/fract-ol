#include "fract_ol.h"

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connect = mlx_init();
	if (NULL =fractal->mlx_connect)
		malloc_error();
	fracta->mlx_window = mlx_new_window(fractal->mlx_connect, mlx_ptr:
			WIDTH, size_x:
			HEIGHT, size_y:
			fractal->name); title:
	if (NULL == fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connect);
		free(fractal->mlx_connect);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connect,
			WIDTH, HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connect, fractal ->mlx_window);
		mlx_destroy_display(fractal->mlx_connect);
		free(fractal->mlx_connect);
		malloc_error();
	}
	
}
