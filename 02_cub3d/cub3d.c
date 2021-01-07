#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "cub3d.h"

int		main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx_project");
	mlx_loop(mlx);
}
