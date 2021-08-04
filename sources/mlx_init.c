#include "fractol.h"

t_mlx		*mlx_data_init()
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->ptr = mlx_init();
		if (!mlx || !mlx->ptr)
			exit (-1);

	mlx->window_ptr = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "Fractol");

	return(mlx);
}

t_image	*image_data_init(t_mlx *mlx)
{
	t_image *image;

	image = NULL;
	image->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	image->addr = (long long*)mlx_get_data_addr(image->img,
		&image->bits_per_pixel, &image->line_length, &image->endian);

	return (image);
}

t_color	*color_data_init()
{
	t_color *color;

	color = NULL;
	color->value = 0x00000000;
	color->alpha = 0x00;
	color->red = 0x00;
	color->green = 0x00;
	color->blue = 0x00;

	return (color);
}
