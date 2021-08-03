#include "fractol.h"

void	fast_pixel_put(t_data *data, int x, int y, int color)
{
	// Bytes are not aligned start after the addres pointer, pixels are bytes in lines(y) so...
	// offset = address + (y * line_length + x * (bits_per_pixel/8))

	char	*dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel/8));
	*(unsigned int *)dest = color;
}

int	main()
{
	void		*mlx;
	void		*win;
	t_data	img;

	// Initialize the connection with Display server;
	mlx = mlx_init();
	if (!mlx)
		exit(-1);

	// Initialize a new window
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fract-ol");

	// Create a new image
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	// Set the address of the image on with the pixels can be mutated
	img.addr = mlx_get_data_addr(img.img,
		&img.bits_per_pixel, &img.line_length, &img.endian);

	// Loop to put pixels in image
	for (int x = 400; x < 500; x++)
		for (int y = 400; y < 500; y++)
		{
			fast_pixel_put(&img, x, y, ft_strtol("0x00FF00", &img.color, 16));
		}

	mlx_put_image_to_window(mlx, win, img.img, 0, 0);

	// Event loop - Mouse/Keyboard
	mlx_loop(mlx);
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
				fast_pixel_put(&img, 1000 + x, 200 + y, 0x0000FF);
		} */
