#include "canvas.h"

Canvas* canvas_make(int w, int h)
{
	Canvas* canvas = malloc(sizeof(Canvas));
	size_t size = sizeof(Color) * w * h;
	canvas->data = malloc(size);
	canvas->w = w;
	canvas->h = h;
	return canvas;
}

void canvas_free(Canvas* canvas)
{
	free(canvas->data);
	free(canvas);
}

void canvas_clear(Canvas* canvas, Color color)
{
	for (int y = 0; y < canvas->h; ++y)
	{
		int offset = y * canvas->w;
		for (int x = 0; x < canvas->w; ++x)
		{
			canvas->data[offset + x] = color;
		}
	}
}

void canvas_set(Canvas* canvas, int x, int y, Color color)
{
	if (color.r > 1) color.r = 1;
	if (color.r < 0) color.r = 0;
	if (color.g > 1) color.g = 1;
	if (color.g < 0) color.g = 0;
	if (color.b > 1) color.b = 1;
	if (color.b < 0) color.b = 0;
	if (x >= 0 && x < canvas->w && y >= 0 && y < canvas->h)
		canvas->data[y * canvas->w + x] = color;
}

Color canvas_at(Canvas* canvas, int x, int y)
{
	if (x >= 0 && x < canvas->w && y >= 0 && y < canvas->h) return canvas->data[y * canvas->w + x];
	return black;
}

void canvas_term(Canvas* canvas)
{
	for (int y = 0; y < canvas->h; ++y)
	{
		for (int x = 0; x < canvas->w; ++x)
		{
			Color color = canvas_at(canvas, x, y);
			char* colorstr = color_term(color, "#");
			printf(colorstr);
			free(colorstr);
		}
		printf("\n");
	}
}
