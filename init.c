#include "fract_ol.h"

static void	malloc_error(void)
{
	perror("Malloc problem");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->esc_value = 4;
	fractal->iterations = 40;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask,
		key_handler, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask,
		mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
		close_handler, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connect = mlx_init();
	if (fractal->mlx_connect == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connect, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connect);
		free(fractal->mlx_connect);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connect,
			WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connect, fractal ->mlx_window);
		mlx_destroy_display(fractal->mlx_connect);
		free(fractal->mlx_connect);
		malloc_error();
	}
	fractal->img.pxl_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	data_init(fractal);
	events_init(fractal);
}
