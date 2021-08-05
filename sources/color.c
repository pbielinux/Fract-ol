#include "fractol.h"

t_color *color_init(void)
{
	t_color	*color;

	color = (t_color *)malloc(sizeof(t_color));

	color->value = 0xFFFFFFFF;
	color->alpha = 0xFF;
	color->red = 0xFF;
	color->green = 0xFF;
	color->blue = 0xFF;

	return (color);
}

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

uint8_t color_compiler(t_color *color, int ch_A, int ch_R, int ch_G, int ch_B)
{
	int new_color;
	// set the color
	new_color = (ch_A << 24 | ch_R << 16 | ch_G << 8 | ch_B);
	// get the channels data
	color->value	= new_color;
	color->alpha	= ch_A;
	color->red		= ch_R;
	color->green	= ch_G;
	color->blue		= ch_B;

	return (new_color);
}
