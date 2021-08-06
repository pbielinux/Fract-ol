#include "fractol.h"

int	key_press(int key, t_core *core)
{
	static int x = 560;
	static int y = 440;
	static int x_length = 100;
	static int y_length = 100;

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

	return (0);
}
