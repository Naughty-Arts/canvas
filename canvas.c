#include "canvas.h"

#include <string.h>
#include <stdlib.h>

Canvas* canvas_create(int width, int height)
{
	Canvas* canvas = malloc(sizeof(Canvas));
	canvas->data = malloc(sizeof(Color) * width * height);
	memset(canvas->data, 0, sizeof(Color) * width * height);
	canvas->width = width;
	canvas->height = height;
	return canvas;
}

void canvas_free(Canvas* canvas)
{
	free(canvas->data);
	free(canvas);
}

void canvas_clear(Canvas* canvas, Color color)
{
	for (int y = 0; y < canvas->height; ++y)
	{
		for (int x = 0; x < canvas->width; ++x)
		{
			canvas->data[y * canvas->width + x] = color;
		}
	}
}

Color canvas_at(Canvas* canvas, int x, int y)
{
	if (x < 0 || x >= canvas->width) black;
	if (y < 0 || y >= canvas->height) black;
	return canvas->data[y * canvas->width + x];
}

void canvas_set(Canvas* canvas, int x, int y, Color color)
{
	if (x < 0 || x >= canvas->width) return;
	if (y < 0 || y >= canvas->height) return;
	canvas->data[y * canvas->width + x] = color;
}

void canvas_to_ppm(FILE* ppm_file, Canvas* canvas)
{
	fprintf(ppm_file, "P3\n");
	fprintf(ppm_file, "%d %d\n", canvas->width, canvas->height);
	fprintf(ppm_file, "255\n");
	for (int y = 0; y < canvas->height; ++y)
	{
		for (int x = 0; x < canvas->width; ++x)
		{
			Color color = canvas->data[y * canvas->width + x];
			int red = color.r * 255;
			int green = color.g * 255;
			int blue = color.b * 255;
			fprintf(ppm_file, "%d %d %d\n", red, green, blue);
		}
	}
}

char* canvas_string(Canvas* canvas)
{
	char* buffer = malloc(sizeof(char) * (canvas->width + 1) * canvas->height + 1);
	char* p = buffer;
	for (int y = 0; y < canvas->height; ++y)
	{
		for (int x = 0; x < canvas->width; ++x)
		{
			Color color = canvas_at(canvas, x, y);
			if (color.r > 0.5)
			{
				p += sprintf(p, "#");
			}
			else
			{
				p += sprintf(p, ".");
			}
		}
		p += sprintf(p, "\n");
	}
	return buffer;
}