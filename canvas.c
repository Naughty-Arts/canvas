#include "canvas.h"

#include <string.h>
#include <stdlib.h>

Canvas* canvas_create(int width, int height)
{
	Canvas* canvas = malloc(sizeof(Canvas));
	canvas->data = malloc(sizeof(c) * width * height);
	memset(canvas->data, 0, sizeof(c) * width * height);
	canvas->width = width;
	canvas->height = height;
	return canvas;
}

void canvas_free(Canvas* canvas)
{
	free(canvas->data);
	free(canvas);
}

void canvas_clear(Canvas* canvas, c color)
{
	for (int y = 0; y < canvas->height; ++y)
	{
		for (int x = 0; x < canvas->width; ++x)
		{
			canvas->data[y * canvas->width + x] = color;
		}
	}
}

c canvas_at(Canvas* canvas, int x, int y)
{
	c b = black;
	if (x < 0 || x >= canvas->width) return b;
	if (y < 0 || y >= canvas->height) return b;
	return canvas->data[y * canvas->width + x];
}

void canvas_set(Canvas* canvas, int x, int y, c color)
{
	if (x < 0 || x >= canvas->width) return;
	if (y < 0 || y >= canvas->height) return;
	if (color.r > 1) color.r = 1;
	if (color.g > 1) color.g = 1;
	if (color.b > 1) color.b = 1;
	if (color.a > 1) color.a = 1;
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
			c color = canvas->data[y * canvas->width + x];
			int r = color.r * 255;
			int g = color.g * 255;
			int b = color.b * 255;
			fprintf(ppm_file, "%d %d %d\n", r, g, b);
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
			c color = canvas_at(canvas, x, y);
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

void canvas_print(Canvas* canvas)
{
	for (int y = 0; y < canvas->height; ++y)
	{
		for (int x = 0; x < canvas->width; ++x)
		{
			c color = canvas_at(canvas, x, y);
			cterm("#", color);
		}
		printf("\n");
	}
}