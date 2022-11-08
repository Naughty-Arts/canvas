#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <color.h>
#include <stdio.h>

typedef struct
{
	int width;
	int height;
	c* data;
} Canvas;

Canvas* canvas_create(int width, int height);
void canvas_free(Canvas* canvas);
void canvas_clear(Canvas* canvas, c color);
c canvas_at(Canvas* canvas, int x, int y);
void canvas_set(Canvas* canvas, int x, int y, c color);
void canvas_to_ppm(FILE* ppm_file, Canvas* canvas);
char* canvas_string(Canvas* canvas);
void canvas_print(Canvas* canvas);

#endif
