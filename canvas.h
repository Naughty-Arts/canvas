#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <color.h>
#include <stdio.h>

typedef struct
{
	int width;
	int height;
	Color* data;
} Canvas;

Canvas* canvas_create(int width, int height);
void canvas_free(Canvas* canvas);
void canvas_clear(Canvas* canvas, Color color);
Color canvas_at(Canvas* canvas, int x, int y);
void canvas_set(Canvas* canvas, int x, int y, Color color);
void canvas_to_ppm(FILE* ppm_file, Canvas* canvas);
char* canvas_string(Canvas* canvas);

#endif
