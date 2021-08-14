#include "fractol.h"

t_fractal	*get_fractal()
{
	static t_fractal array[3] = {
					{"mandelbrot", mandelbrot_viewport, mandelbrot_pixel}
	};

	return (&array[0]);
}
