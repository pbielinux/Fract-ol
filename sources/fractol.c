#include "fractol.h"

void	fast_pixel_put(t_image *image, int x, int y, uint8_t color)
{
	// Bytes are not aligned start after the addres pointer, pixels are bytes in lines(y) so...
	// offset = address + (y * line_length + x * (bits_per_pixel/8))
	long long	*dest;

	dest = image->addr + (y * image->line_length + x * (image->bits_per_pixel/8));
	*dest = (long long)color;
}

int	main()
{
	t_mlx		*mlx;
	t_image	*image;
	t_color	*color;
	uint8_t	color_to_print;

	mlx = mlx_data_init();
	image = image_data_init(mlx);
	color = color_data_init();

	int a = 0;
	int r = 200;
	int g = 100;
	int b = 50;
	// Loop to put pixels in image
	for (int x = 0; x <= 512; x++)
	{
		for (int y = 0; y <= 512; y++)
		{
			color_to_print = color_compiler(color, a, r, g, b);
			fast_pixel_put(image, x, y, color->value);
		}
	}

/* 	mlx_put_image_to_window(mlx->ptr, mlx->window_ptr, image->addr, 400, 200);

	// Event loop - Mouse/Keyboard
	mlx_loop(mlx->ptr); */
}

/* 	// Print circle
	const double PI = 3.1415926535;
	double i, angle, x, y;
	for(int r = 0; r < 100; r++)
		for (i = 0; i < 360; i += 0.1)
		{
				angle = i;
				x = r * cos(angle * PI / 180);
				y = r * sin(angle * PI / 180);
				fast_pixel_put(&image, 1000 + x, 200 + y, 0x0000FFFF);
		} */
