#include "../include/fdf.h"

// Extracted logic for setting z and color values
static void	set_z_and_colors(t_fdf *data, t_line_points *p,
	int *color1, int *color2)
{
	data->side.z1 = data->dmap.input_map[p->y1][p->x1][0];
	data->side.z2 = data->dmap.input_map[p->y2][p->x2][0];
	*color1 = data->dmap.input_map[p->y1][p->x1][1];
	*color2 = data->dmap.input_map[p->y2][p->x2][1];
	if (*color1 == -1)
		*color1 = get_default_color(data->side.z1, data);
	if (*color2 == -1)
		*color2 = get_default_color(data->side.z2, data);
}

// Extracted logic for boundary check
static int	is_out_of_bounds(int x1, int x2, int y1, int y2)
{
	return ((x1 < 0 && x2 < 0) || (x1 > WIDTH && x2 > WIDTH)
		|| (y1 < 0 && y2 < 0) || (y1 > HEIGHT && y2 > HEIGHT));
}

// Extracted slope logic
static void	draw_slope(t_line_points p, t_fdf *data, int color1, int color2)
{
	t_point	start;
	t_point	end;

	start.x = p.x1;
	start.y = p.y1;
	start.color = color1;
	end.x = p.x2;
	end.y = p.y2;
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

	p.x2 = x2;
	p.y2 = y2;
	set_z_and_colors(data, &p, &color1, &color2);
	reproduce_pixels(&p, data);
	locate(&p, data);
	isometric(&p.x1, &p.y1, data->side.z1);
	isometric(&p.x2, &p.y2, data->side.z2);
	if (is_out_of_bounds(p.x1, p.x2, p.y1, p.y2))
		return ;
	data->side.dx = p.x2 - p.x1;
	data->side.dy = p.y2 - p.y1;
	draw_slope(p, data, color1, color2);
}