#include "../../headers/fractol.h"

void	text_put(t_ctx *ctx, char *str, int x, int y)
{
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr, x, y, 0x000000, str);
}

void	pixel_put(t_buff *buff, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	*(int *)(buff->addr + ((x + y * WIDTH) * buff->bits_per_pixel)) = color;
}
