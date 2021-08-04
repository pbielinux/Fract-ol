#include "fractol.h"

void	fast_pixel_put(t_fractol *fractol, int x, int y, uint8_t color)
{
	// Bytes are not aligned start after the addres pointer, pixels are bytes in lines(y) so...
	// offset = address + (y * line_length + x * (bits_per_pixel/8))
	char	*dest;

	dest = fractol->image->data_addr + (y * fractol->image->line_length + x * (fractol->image->bits_per_pixel/8));
	*dest = color;
}

int	main()
{
	void			*mlx;
	t_fractol	*fractol;
	t_color		*color;

	mlx = mlx_init();

	fractol = fractol_init(mlx);
	color = color_init();

	for (int x = 0; x <= 512; x++)
	{
		color->value = color_compiler(color, 0, 0, 0, 255);
		for (int y = 0; y <= 512; y++)
		{
			fast_pixel_put(fractol, x, y, color->value);
		}
	}

	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->image->image, 0, 0);

	mlx_loop(mlx);
}

/* 	int a = 0;
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
	} */


/* 	mlx_put_image_to_window(mlx->ptr, mlx->window_ptr, image->addr, 400, 200);
	// Event loop - Mouse/Keyboard
	mlx_loop(mlx->ptr); */

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
