#include "fractol.h"

static void	ft_print_err(t_exit_code exit_code);

void	ft_exit_error(t_core *core, t_exit_code exit_code)
{
	ft_print_err(exit_code);
	ft_free_core(core);
	exit(EXIT_FAILURE);
}

static void	ft_print_err(t_exit_code exit_code)
{

	if (exit_code == MEMORY_FAIL)
		printf("Error: Can't allocate memory\n");
	else if (exit_code == BUFF_NOT_SET)
		printf("Error: Buffer not setted\n");
	else if (exit_code == BUFF_ADDR_NOT_SET)
		printf("Error: Buffer address not setted\n");
	else if (exit_code == MLX_INIT_FAIL)
		printf("Error: Cannot stablish a connection with Display Server\n");
	else
		printf("Error: Unknown error\n");
}