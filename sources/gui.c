#include "fractol.h"

void	draw_rect(t_buff *image, int x_start, int x_len, int y_start, int y_len)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if ((x >= x_start && x - x_start < x_len)
				&& (y >= y_start && y - y_start < y_len))
				pixel_put(image, x, y, 0xAA000000);
			else
				pixel_put(image, x, y, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
}

void	draw_gui(t_core *core)
{
	char	*relative_path = "./sources/GUI.xpm";

	core->ctx->gui->img = mlx_xpm_file_to_image(core->ctx->mlx_ptr, relative_path, &core->ctx->gui->width, &core->ctx->gui->height);
}
