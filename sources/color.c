#include "fractol.h"

uint8_t get_opposite_color(t_color color)
{
	uint8_t new_color;

	new_color = 0x00000000;

	new_color |= color.alpha	<< 24;
	new_color |= color.red		<< 16;
	new_color |= color.green	<< 8;
	new_color |= color.blue;

	return (new_color);
}

uint8_t	color_compiler(t_color *color, int ch_A, int ch_R, int ch_G, int ch_B)
{
	color->value = 0x00000000;

	// set the color
	color->value |= ch_A << 24;
	color->value |= ch_R << 16;
	color->value |= ch_G << 8;
	color->value |= ch_B;
	// get the channels data
	color->alpha	= color->value & (0xFF << 24);
	color->red		= color->value & (0xFF << 16);
	color->green	= color->value & (0xFF << 8);
	color->blue		= color->value & (0xFF);

	return (color->value);
}
