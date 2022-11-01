#include <stdio.h>

#include "canvas.h"

int main()
{
	printf("------------------ Canvas -------------------- \n");

	Canvas* canvas = canvas_create(32, 16);

	for (int i = 8; i < 24; ++i)
	{
		for (int j = 4; j < 6; ++j)
		{
			canvas_set(canvas, i, j, red);
		}
	}

	printf(canvas_string(canvas));

	return 0;
}
