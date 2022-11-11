#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <color.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int w;
	int h;
	Color* data;
} Canvas;

Canvas* canvas_make(int w, int h);
void canvas_free(Canvas* canvas);
void canvas_clear(Canvas* canvas, Color color);
void canvas_set(Canvas* canvas, int x, int y, Color color);
Color canvas_at(Canvas* canvas, int x, int y);
void canvas_term(Canvas* canvas);

#endif
