#include "fractol.h"

void	set_defaults(t_fractol *fractol)
{
	fractol->max_iteration = 50;
}

t_fractol	*fractol_init(void *mlx)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		exit (-1);

	fractol->mlx = mlx;

	fractol->window = mlx_new_window(mlx, WIDTH, HEIGHT, "Fractol");
	if (!fractol->window)
		exit (-1);

	fractol->image = image_init(mlx);
	set_defaults(fractol);

	return(fractol);
}
