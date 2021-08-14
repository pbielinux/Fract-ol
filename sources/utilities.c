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

void		fps_count(t_core *core)
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
		text_put(core->ctx, "FPS:", 20, 90, 0xFFFFFFFF);
		text_put(core->ctx, str, 60, 90, 0xFFFFFFFF);
	}
}
