#include "fractol.h"

t_image *image_init(void *mlx)
{
	t_image *image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		exit (-1);

	image->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image->image)
		exit (-1);

	image->image_addr = mlx_get_data_addr(
		image->image,
		&image->bits_per_pixel,
		&image->line_length,
		&image->endian);

	return (image);
}
