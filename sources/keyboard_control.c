#include "fractol.h"

int	key_press(int key, t_core *core)
{
	static int x = 560;
	static int y = 440;
	static int x_length = 100;
	static int y_length = 100;
	static int a = 0x00;
	static int r = 0x00;
	static int g = 0x00;
	static int b = 0x00;
	static int maxIterations = 20;
	static double zoom = 2.5;

	if (key == KB_ESC)
		exit(0);

	if (key == KB_UP)
	{
		ft_putstr("Key UP\n");
		bzero(core->ctx->buff->addr, WIDTH * HEIGHT * (core->ctx->buff->bits_per_pixel / 8));
		draw_rect(core, x, x_length, y -= 15, y_length);
	}
	if (key == KB_DOWN)
	{
		ft_putstr("Key DOWN\n");
		bzero(core->ctx->buff->addr, WIDTH * HEIGHT * (core->ctx->buff->bits_per_pixel / 8));
		draw_rect(core, x, x_length, y += 15, y_length);
	}
	if (key == KB_LEFT)
	{
		ft_putstr("Key LEFT\n");
		bzero(core->ctx->buff->addr, WIDTH * HEIGHT * (core->ctx->buff->bits_per_pixel / 8));
		draw_rect(core, x -= 15, x_length, y, y_length);
	}
	if (key == KB_RIGHT)
	{
		ft_putstr("Key RIGHT\n");
		ft_bzero(core->ctx->buff->addr, WIDTH * HEIGHT * (core->ctx->buff->bits_per_pixel / 8));
		draw_rect(core, x += 15, x_length, y, y_length);
	}

	if (key == KB_PLUS)
	{
		ft_putstr("Key PLUS\n");
		bzero(core->ctx->buff->addr, WIDTH * HEIGHT * (core->ctx->buff->bits_per_pixel / 8));
		draw_rect(core, x -= 5, x_length += 5, y -= 5, y_length += 5);
	}
	if (key == KB_MINUS)
	{
		ft_putstr("Key MINUS\n");
		bzero(core->ctx->buff->addr, WIDTH * HEIGHT * (core->ctx->buff->bits_per_pixel / 8));
		draw_rect(core, x += 5, x_length -= 5, y += 5, y_length -= 5);
	}


	if (key == KB_W)
	{
		ft_putstr("Key W\n");
		bzero(core->ctx->buff->addr, WIDTH * HEIGHT * (core->ctx->buff->bits_per_pixel / 8));
		draw_fract(core, maxIterations++, zoom);
	}
	if (key == KB_S)
	{
		ft_putstr("Key S\n");
		bzero(core->ctx->buff->addr, WIDTH * HEIGHT * (core->ctx->buff->bits_per_pixel / 8));
		draw_fract(core, maxIterations--, zoom);
	}
	if (key == KB_A)
	{
		ft_putstr("Key A\n");
		bzero(core->ctx->buff->addr, WIDTH * HEIGHT * (core->ctx->buff->bits_per_pixel / 8));
		draw_fract(core, maxIterations, zoom += 0.1);
	}
	if (key == KB_D)
	{
		ft_putstr("Key D\n");
		bzero(core->ctx->buff->addr, WIDTH * HEIGHT * (core->ctx->buff->bits_per_pixel / 8));
		draw_fract(core, maxIterations, zoom -= 0.1);
	}

	if (key == KB_A)
	{
		ft_putstr("Key A\n");
		core->ctx->color = new_color(a+=5 , r , g, b);
	}
	if (key == KB_R)
	{
		ft_putstr("Key R\n");
		core->ctx->color = new_color(a, r+=5, g, b);
	}
	if (key == KB_G)
	{
		ft_putstr("Key G\n");
		core->ctx->color = new_color(a, r, g+=5, b);
	}
	if (key == KB_B)
	{
		ft_putstr("Key B\n");
		core->ctx->color = new_color(a, r , g, b+=5);
	}

	return (0);
}
