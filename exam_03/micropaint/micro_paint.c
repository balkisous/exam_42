

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct s_zone
{
	int	width;
	int	height;
	char	backg;
}		t_zone;

typedef struct s_shape
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	color;
}		t_shape;

int	ft_strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

int	str_error(char *str, int ret)
{
	write(1, str, ft_strlen(str));
	return (ret);
}

int	clear_all(FILE *file, char *draw, char *str)
{
	fclose(file);
	if (draw)
		free(draw);
	if (str)
		return(str_error(str, 1));
	return (1);
}

int	check_zone(t_zone *zone)
{
	return(zone->width > 0 && zone->width < 300 && zone->height > 0 && zone->height < 300);
}

int	check_shape(t_shape *shape)
{
	return(shape->width > 0 && shape->height > 0 &&(shape->type == 'r' || shape->type == 'R'));
}

int	get_zone(FILE *file, t_zone *zone)
{
	int	sret;

	if ((sret = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->backg))!= 3)
		return (0);
	if (!check_zone(zone))
		return (0);
	if (sret == -1)
		return (0);
	return (1);
}

char	*paint_backg(t_zone *zone)
{
	char	*draw;
	int	i = 0;
	if (!(draw = (char*)malloc(sizeof(*draw) * (zone->width * zone->height))))
		return (0);
	while (i < (zone->width * zone->height))
	{
		draw[i] = zone->backg;
		i++;
	}
	return (draw);
}

int	in_rect(float x, float y, t_shape *shape)
{
	if ((x < shape->x) || ((shape->width + shape->x) < x) || (y < shape->y) || ((shape->y + shape->width) < y))
		return (0);
	if (((x - shape->x) < 1) || (((shape->width + shape->x)- x) < 1) || ((y - shape->y) < 1) || (((shape->y + shape->width)- y) < 1))
		return (2);
	return (1);
}

void	draw_shape(char *draw, t_zone *zone, t_shape *shape)
{
	int	i = 0;
	int	j;
	int	ret;

	while (i < zone->height)
	{
		j = 0;
		while (j < zone->width)
		{
			ret = in_rect(j, i, shape);
			if ((ret == 2 && shape->type == 'r') || (ret && shape->type == 'R'))
				draw[(i * zone->width) + j] = shape->color;
			j++;
		}
		i++;
	}
}
int	draw_shapes(FILE *file, char *draw, t_zone *zone)
{
	t_shape	tmp;
	int	sret;

	while((sret = fscanf(file, "%c %f %f %f %f %c", &tmp.type, &tmp.x, &tmp.y, &tmp.width, &tmp.height, &tmp.color)) == 6)
	{
		if (!check_shape(&tmp))
			return (0);
		draw_shape(draw, zone, &tmp);
	}
//	if (sret != -1)
//		return (0);
	return (1);
}

void	draw_drawing(char *draw, t_zone *zone)
{
	int	i;

	i = 0;
	while (i < zone->height)
	{
		write(1, draw +(i *zone->width), zone->width);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	FILE	*file;
	t_zone	zone;
	char	*draw;

	zone.width = 0;
	zone.height = 0;
	zone.backg = 0;
	draw = NULL;
	if (argc != 2)
		return (str_error("Error argument\n", 1));
	if (!(file = fopen(argv[1], "r")))
		return (str_error("Error file\n", 1));
	if (!get_zone(file, &zone))
		return (clear_all(file , NULL, "Error file\n"));
	if (!(draw = paint_backg(&zone)))
		return (clear_all(file, NULL, "malloc echoue"));
	if (!draw_shapes(file, draw, &zone))
		return (clear_all(file, draw, "file probleme, j'ai envie de dormir lol\n"));
	draw_drawing(draw, &zone);
	clear_all(file, draw, NULL);
	return (0);
}
