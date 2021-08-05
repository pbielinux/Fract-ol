#include "fractol.h"

int	close_program(void *param)
{
	(void)param;
	exit(0);
}

void	draw_square(t_fractol *fractol, int x_start, int x_length, int y_start, int y_length, t_color *color)
{
	int x;
	int y;

	ft_bzero(fractol->image->image_addr,
		WIDTH * HEIGHT * (fractol->image->bits_per_pixel / 8));

	color_compiler(color, 0, 0, 255, 80);
	y = 0;
	while (y <= y_length)
	{
		x = 0;
		while (x <= x_length)
		{
			fast_pixel_put(fractol, x_start + x, y_start + y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->image->image, 0, 0);
}
