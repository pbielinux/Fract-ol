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
	mlx_put_image_to_window(core->ctx->mlx_ptr, core->ctx->win_ptr,
		core->gui->img, 0, 0);
}

void	draw_window(t_core *core, int x, int y)
{
	mlx_put_image_to_window(core->ctx->mlx_ptr, core->ctx->win_ptr,
		core->window->img, x, y);
}

void	draw_configs(t_core *core, int x, int y)
{
	mlx_put_image_to_window(core->ctx->mlx_ptr, core->ctx->win_ptr,
		core->configs->img, x, y);
	text_put(core->ctx, ft_itoa(core->ctx->viewport.max), x + 85, y + 186, 0x00000000);
}
