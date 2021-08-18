#include "fractol.h"

t_fractal	*get_fractal(int index)
{
	static t_fractal	array[4];

	array[0] = (t_fractal){"Mandelbrot",
		mandelbrot_viewport, mandelbrot_pixel};
	array[1] = (t_fractal){"Julia",
		julia_viewport, julia_pixel};
	array[2] = (t_fractal){"Burningship",
		burningship_viewport, burningship_pixel};
	array[3] = (t_fractal){NULL, NULL, NULL};
	if (index)
		return (&array[index - 1]);
	else
		return (array);
}

t_fractal	*fractal_search(char *str)
{
	int			i;
	t_fractal	*fractal;

	fractal = get_fractal(0);
	i = 0;
	while (fractal[i].name != NULL)
	{
		if (!ft_strncmp(fractal[i].name, str, 3))
			return (&fractal[i]);
		i++;
	}
	return (&fractal[i]);
}
