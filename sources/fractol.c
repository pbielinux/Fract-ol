#include "fractol.h"

void	fast_pixel_put(t_fractol *fractol, int x, int y, t_color *color)
{
	// Bytes are not aligned start after the addres pointer, pixels are bytes in lines(y) so...
	// offset = address + (y * line_length + x * (bits_per_pixel/8))
	char	*offset;

	offset = fractol->image->image_addr + ((y * fractol->image->line_length) + (x * fractol->image->bits_per_pixel / 8));
	*(unsigned int *)offset = color->value;

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
		color_compiler(color, 0, 0, 70, 200);
		for (int y = 0; y <= 512; y++)
		{
			fast_pixel_put(fractol, x, y, color);
		}
	}

	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->image->image, 0, 0);

	mlx_loop(mlx);
}
