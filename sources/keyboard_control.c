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

	if (key == KB_ESC)
		exit(0);

	if (key == KB_UP)
		draw_rect(core, x, x_length, y -= 15, y_length);
	if (key == KB_DOWN)
		draw_rect(core, x, x_length, y += 15, y_length);
	if (key == KB_LEFT)
		draw_rect(core, x -= 15, x_length, y, y_length);
	if (key == KB_RIGHT)
		draw_rect(core, x += 15, x_length, y, y_length);

	if (key == KB_PLUS)
		draw_rect(core, x -= 5, x_length += 5, y -= 5, y_length += 5);
	if (key == KB_MINUS)
		draw_rect(core, x += 5, x_length -= 5, y += 5, y_length -= 5);

	if (key == KB_A)
		core->ctx->color->value = new_color(a += 5, r , g, b);
	if (key == KB_R)
		core->ctx->color->value = new_color(a, r += 5, g, b);
	if (key == KB_G)
		core->ctx->color->value = new_color(a, r, g += 5, b);
	if (key == KB_B)
		core->ctx->color->value = new_color(a, r , g, b += 5);


	return (0);
}
