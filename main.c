#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "canvas.h"

int main()
{
	printf("------------------ Canvas -------------------- \n");

	Canvas* canvas = canvas_make(32, 16);

	color_init();

	canvas_clear(canvas, forest_green);

	for (int i = 8; i < 24; ++i)
	{
		for (int j = 4; j < 6; ++j)
		{
			canvas_set(canvas, i, j, red);
		}
	}

	for (int i = 0; i < 32; ++i)
	{
		canvas_set(canvas, i, 0, blue);
		canvas_set(canvas, i, 15, blue);
	}

	for (int i = 0; i < 16; ++i)
	{
		canvas_set(canvas, 0, i, blue);
		canvas_set(canvas, 31, i, blue);
	}

	canvas_term(canvas);
	printf("\n");

	return 0;
}
