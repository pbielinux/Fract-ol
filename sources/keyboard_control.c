#include "fractol.h"

void		zoom(int x, int y, t_view *viewport, double zoom)
{
	double width;
	double height;
	double new_width;
	double new_height;

	width = (viewport->x_max - viewport->x_min) * (viewport->zoom);
	height = (viewport->y_max - viewport->y_min) * (viewport->zoom);
	new_width = (viewport->x_max - viewport->x_min) * (viewport->zoom * zoom);
	new_height = (viewport->y_max - viewport->y_min) * (viewport->zoom * zoom);
	viewport->zoom *= zoom;
	viewport->off_x -= ((double)x / WIDTH) * (new_width - width);
	viewport->off_y -= ((double)y / HEIGHT) * (new_height - height);
}

void	move(int key, t_core *core)
{
	double width;
	double height;

	width = (core->viewport.x_max - core->viewport.x_min) * core->viewport.zoom;
	height = (core->viewport.y_max - core->viewport.y_min) * core->viewport.zoom;

	if (key == KB_UP)
	{
		ft_putstr("Key W\n");
		core->viewport.off_y -= height * 0.05f;
	}
	if (key == KB_DOWN)
	{
		ft_putstr("Key W\n");
		core->viewport.off_y += height * 0.05f;
	}
	if (key == KB_LEFT)
	{
		ft_putstr("Key W\n");
		core->viewport.off_x -= width * 0.05f;
	}
	if (key == KB_RIGHT)
	{
		ft_putstr("Key W\n");
		core->viewport.off_x += width * 0.05f;
	}
}

int	key_press(int key, t_core *core)
{
	static int a = 0x00;
	static int r = 0x00;
	static int g = 0x00;
	static int b = 0x00;

	bzero(core->ctx->buff->addr, WIDTH * HEIGHT * (core->ctx->buff->bits_per_pixel / 8));

	move(key, core);

	if (key == KB_ESC)
	{
		ft_putstr("Key ESC\n");
		exit(0);
	}

	if (key == KB_PLUS)
		zoom(WIDTH / 2, HEIGHT / 2, &core->viewport, 1 / 1.1f);
	if (key == KB_MINUS)
		zoom(WIDTH / 2, HEIGHT / 2, &core->viewport, 1.1f);

	if (key == KB_W)
		core->viewport.max++;

	if (key == KB_S)
		core->viewport.max--;

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

	draw_fract(core);
	return (0);
}
