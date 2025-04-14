/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szmadeja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:01:45 by szmadeja          #+#    #+#             */
/*   Updated: 2025/04/14 17:08:18 by szmadeja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
//#include "fract-ol.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "hello world");
	mlx_loop(mlx);
}
