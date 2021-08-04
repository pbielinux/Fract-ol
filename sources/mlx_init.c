#include "fractol.h"

void	set_defaults(t_fractol *fractol)
{
	fractol->max_iteration = 50;
}

t_image *image_init(void *mlx)
{
	t_image *image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		exit (-1);

	image->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image->image)
		exit (-1);

	image->data_addr = mlx_get_data_addr(
		image->image,
		&image->bits_per_pixel,
		&image->line_length,
		&image->endian);

	return (image);
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

t_color *color_init(void)
{
	t_color	*color;

	color = (t_color *)malloc(sizeof(t_color));

	return (color);
}
