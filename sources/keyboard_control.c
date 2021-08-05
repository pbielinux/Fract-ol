#include "fractol.h"

int	key_press(int key, t_fractol *fractol)
{
	(void)fractol;
	static int x = 560;
	static int y = 440;
	static int x_length = 100;
	static int y_length = 100;

	if (key == KB_ESC)
		exit(0);

	if (key == KB_UP)
		draw_square(fractol, x, x_length, y -= 15, y_length, fractol->color);
	if (key == KB_DOWN)
		draw_square(fractol, x, x_length, y += 15, y_length, fractol->color);
	if (key == KB_LEFT)
		draw_square(fractol, x -= 15, x_length, y, y_length, fractol->color);
	if (key == KB_RIGHT)
		draw_square(fractol, x += 15, x_length, y, y_length, fractol->color);

	if (key == KB_PLUS)
		draw_square(fractol, x -= 5, x_length += 5, y -= 5, y_length += 5, fractol->color);
	if (key == KB_MINUS)
		draw_square(fractol, x += 5, x_length -= 5, y += 5, y_length -= 5, fractol->color);

	return (0);
}
