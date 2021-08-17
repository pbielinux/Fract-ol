#include "fractol.h"

t_palette	get_palette(int palette)
{
	if (palette == 1)
		return ((t_palette){5,
			{0x1f0047, 0x3a00AA, 0x10b5c4, 0xFFB733, 0xC22121}});
	else if (palette == 2)
		return ((t_palette){5,
			{0x000000, 0x00EE00, 0xFFBF02, 0xDD00DD, 0x5000FF}});
	else if (palette == 3)
		return ((t_palette){3,
			{0x000000, 0xC22121, 0xFF1133}});
	else if (palette == 4)
		return ((t_palette){3,
			{0x000000, 0x00EE00, 0xFFBF02}});
	else
		return ((t_palette){0, {0}});
}
