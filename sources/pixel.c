#include "fractol.h"

void	text_put(t_ctx *ctx, char *str, int x, int y, int color)
{
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr, x, y, color, str);
}

void	pixel_put(t_buff *buff, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;

	*(int *)(buff->img + ((x + y * WIDTH) * buff->bits_per_pixel)) = color;
}
