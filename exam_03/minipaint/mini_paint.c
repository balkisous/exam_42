


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct s_zone
{
	int		width;
	int		height;
	char	backg;
}				t_zone;

typedef struct s_shape
{
	char	type;
	float	x;
	float	y;
	float	radius;
	char	color;
}			t_shape;

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		str_error(char *str, int ret)
{
	write(1, str, ft_strlen(str));
	return (ret);
}

int		clear_all(FILE *file, char *draw, char *str)
{
	fclose(file);
	if (draw)
		free(draw);
	if (str)
		return (str_error(str, 1));
	return (1);
}

int		check_zone(t_zone *zone)
{
	return (zone->width > 0 && zone->height > 0 && zone->width < 300 && zone->height < 300);
}

int		check_shape(t_shape *shape)
{
	return (shape->radius > 0 && (shape->type == 'C' || shape->type == 'c'));
}

int		in_circle(float x, float y, t_shape *shape)
{
	float	distance;

	distance = sqrt(powf(x - shape->x, 2.) + powf(y - shape->y, 2.));
	if (distance <= shape->radius)
	{
		if ((shape->radius - distance) < 1)
			return (2);
		return (1);
	}
	return (0);
}

int		get_zone(FILE *file, t_zone *zone)
{
	int		scan_ret;

	if ((scan_ret = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->backg))!= 3)
		return (0);
	if (!check_zone(zone))
		return (0);
	if (scan_ret == -1)
		return (0);
	return (1);
}

char	*paint_backg(t_zone *zone)
{
	int		i;
	char	*draw;

	if (!(draw = (char *)malloc(sizeof(draw) * (zone->width * zone->height))))
		return (0);
	i = 0;
	while (i < (zone->width * zone->height))
	{
		draw[i] = zone->backg;
		i++;
	}
	return (draw);
}

void	draw_shape(t_zone *zone, t_shape *shape, char *draw)
{
	int		x;
	int		y;
	int		ret;
	
	y = 0;
	while (y < zone->height)
	{
		x = 0;
		while (x < zone->width)
		{
			ret = in_circle((float)x, (float)y, shape);
			if ((ret == 2 && shape->type == 'c') || (ret && shape->type == 'C'))
				draw[(zone->width *y) + x] = shape->color;
			x++;
		}
		y++;
	}
}

int		draw_shapes(FILE *file, char *draw, t_zone *zone)
{
	t_shape	tmp;
	int		ret_scan;

	while ((ret_scan = fscanf(file, "%c %f %f %f %c\n", &tmp.type, &tmp.x, &tmp.y, &tmp.radius, &tmp.color)) == 5)
	{
		if (!check_shape(&tmp))
			return (0);
		draw_shape(zone, &tmp, draw);
	}
	if (ret_scan != -1)
		return (0);	
	return (1);
}

void	draw_drawing(char *draw, t_zone *zone)
{
	int		i;

	i = 0;
	while(i < zone->height)
	{
		write(1, draw + (i * zone->width), zone->width);
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char **argv)	
{
	FILE	*file;
	t_zone	zone;
	char	*draw;

	zone.width = 0;
	zone.height = 0;
	zone.backg = 0;
	if (argc != 2)
		return (str_error("Error: argument\n", 1));
	if (!(file = fopen(argv[1], "r")))
		return (str_error("Error: Operation file corrupted\n", 1));
	if (!get_zone(file, &zone))
		return (clear_all(file, NULL, "Error: Operation file corrupted\n"));
	if (!(draw = paint_backg(&zone)))
		return (clear_all(file, NULL, "Error: Operation file corrupted\n"));
	if (!draw_shapes(file, draw, &zone))
		return (clear_all(file, draw, "Error: Operation file corrupted\n"));
	draw_drawing(draw, &zone);
	clear_all(file, draw, NULL);
	return (0);
}
