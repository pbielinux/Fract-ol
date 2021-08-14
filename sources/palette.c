#include "fractol.h"

t_palette	get_palette(int index)
{
	if (index == 1)
		return ((t_palette){5, {0x3a0071,0x047878,0xFFB733,0xF57336,0xC22121}});
	else if (index == 2)
		return ((t_palette){5, {0x1f0047,0x3a00AA,0x10b5c4,0xFFB733,0xC22121}});
	else
		return ((t_palette){0, {0}});
}
