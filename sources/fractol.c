#include "fractol.h"

int	main()
{
	void			*mlx;
	t_fractol	*fractol;

	mlx = mlx_init();
	fractol = fractol_init(mlx);

	mlx_hook(fractol->window, 2, 0, key_press, fractol);
	mlx_hook(fractol->window, 17, 0, close_program, fractol);

	mlx_loop(mlx);
}
