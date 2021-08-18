#include "fractol.h"

int	close_program(void *param)
{
	(void)param;
	exit(0);
}

void	fps_count(t_core *core)
{
	static time_t	str_time = 0;
	static int		count = 0;
	static char		*str = NULL;

	if (str_time == 0)
		str_time = time(0);
	if (time(0) - str_time >= 1)
	{
		str_time = time(0);
		free(str);
		str = ft_itoa(count);
		count = 0;
	}
	else
		count++;
	if (str != NULL)
	{
		text_put(core->ctx, "FPS:", 20, 50);
		text_put(core->ctx, str, 60, 5);
	}
}

void	clear_image(t_buff *image, int	width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < width)
	{
		x = 0;
		while (x < height)
		{
			pixel_put(image, x, y, 0xFF000000);
			x++;
		}
		y++;
	}
}
