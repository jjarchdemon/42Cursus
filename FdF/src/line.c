/* ************************************************************************** */

#include "../include/fdf.h"

// Extracted logic for setting z and color values
static void	set_z_and_colors(t_fdf *data, t_line_points *p,
	int *color1, int *color2)
{
	data->side.z1 = data->dmap.input_map[p->start.y][p->start.x][0];
	data->side.z2 = data->dmap.input_map[p->end.y][p->end.x][0];
	*color1 = data->dmap.input_map[p->start.y][p->start.x][1];
	*color2 = data->dmap.input_map[p->end.y][p->end.x][1];
	if (*color1 == -1)
		*color1 = get_default_color(data->side.z1, data);
	if (*color2 == -1)
		*color2 = get_default_color(data->side.z2, data);
}

// Extracted logic for boundary check
static int	is_out_of_bounds(t_point start, t_point end)
{
	return ((start.x < 0 && end.x < 0) || (start.x > WIDTH && end.x > WIDTH)
		|| (start.y < 0 && end.y < 0) || (start.y > HEIGHT && end.y > HEIGHT));
}

// Extracted slope logic
static void	draw_slope(t_line_points p, t_fdf *data, int color1, int color2)
{
	t_point	start;
	t_point	end;

	start.x = p.start.x;
	start.y = p.start.y;
	start.color = color1;
	end.x = p.end.x;
	end.y = p.end.y;
	end.color = color2;
	if (abs(data->side.dx) > abs(data->side.dy))
		negative_slope(start, end, data);
	else
		positive_slope(start, end, data);
}

void	line(int x2, int y2, t_fdf *data, t_line_points p)
{
	int	color1;
	int	color2;

	p.end.x = x2;
	p.end.y = y2;
	set_z_and_colors(data, &p, &color1, &color2);
	reproduce_pixels(&p, data);
	locate(&p, data);
	isometric(&p.start.x, &p.start.y, data->side.z1);
	isometric(&p.end.x, &p.end.y, data->side.z2);
	if (is_out_of_bounds(p.start, p.end))
		return ;
	data->side.dx = p.end.x - p.start.x;
	data->side.dy = p.end.y - p.start.y;
	draw_slope(p, data, color1, color2);
}
