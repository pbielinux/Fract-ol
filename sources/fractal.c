#include "fractol.h"

t_fractal	*get_fractal(int index)
{
	static t_fractal array[3] = {
					{"Mandelbrot Set", mandelbrot_viewport, mandelbrot_pixel},
					{"julia Set", julia_viewport, julia_pixel}
	};

	return (&array[index - 1]);
}
