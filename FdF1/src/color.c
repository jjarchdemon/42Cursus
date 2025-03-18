/* ************************************************************************** */
#include "../include/fdf.h"

unsigned int get_color(int z1, int z2)
{
    float	blended;
    int	red;
    int	green;

    blended = (((z1 + z2) / 2.0) + 30.0) / 110.0;
    red = (int)(blended * 255);
    green = (int)((1 - blended) * 255);
    return ((red << 16) | (green << 8) | 150);
}
