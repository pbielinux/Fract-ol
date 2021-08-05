#include "fractol.h"

void	fast_pixel_put(t_fractol *fractol, int x, int y, t_color *color)
{
	// Bytes are not aligned start after the addres pointer, pixels are bytes in lines(y) so...
	// offset = address + (y * line_length + x * (bits_per_pixel/8))
	char	*offset;

	offset = fractol->image->image_addr + ((y * fractol->image->line_length) + (x * fractol->image->bits_per_pixel / 8));
	*(unsigned int *)offset = color->value;
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

	image->image_addr = mlx_get_data_addr(
		image->image,
		&image->bits_per_pixel,
		&image->line_length,
		&image->endian);

	return (image);
}
