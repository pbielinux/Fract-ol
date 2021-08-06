#include "fractol.h"

int	close_program(void *param)
{
	(void)param;
	exit(0);
}

void	draw_rect(t_core *core, int x_start, int x_length, int y_start, int y_length)
{
	int x;
	int y;

	ft_bzero(core->ctx->buff->addr,
		WIDTH * HEIGHT * (core->ctx->buff->bits_per_pixel / 8));

	y = 0;
	while (y <= y_length)
	{
		x = 0;
		while (x <= x_length)
		{
			pixel_put(core->ctx->buff, x_start + x, y_start + y, core->ctx->color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(core->ctx->mlx_ptr, core->ctx->win_ptr, core->ctx->buff->img, 0, 0);
}
