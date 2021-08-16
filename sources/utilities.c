#include "fractol.h"

void	exit_program(t_core *core, int error_code, char *msg)
{
	(void)core;
	if (error_code != 0)
		ft_putstr(RED);
	else
		ft_putstr(GRN);
	ft_putstr("\nProgram Exit - Error: ");
	ft_putnbr(error_code);
	ft_putstr(" - ");
	ft_putstr(msg);
	ft_putstr("\n"RST);
	ft_putstr(GRN"Exit Done\n"RST);
	exit(0);
}

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
		text_put(core->ctx, "FPS:", 20, 50, 0xFFFFFFFF);
		text_put(core->ctx, str, 60, 50, 0xFFFFFFFF);
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
