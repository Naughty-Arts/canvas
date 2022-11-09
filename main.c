#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "canvas.h"

int main()
{
	printf("------------------ Canvas -------------------- \n");

	canvas* canvas;
	canvas_make(canvas, 32, 16);

	c r = cred;
	c b = cblue;

	for (int i = 8; i < 24; ++i)
	{
		for (int j = 4; j < 6; ++j)
		{
			canvas_set(canvas, i, j, r);
		}
	}

	for (int i = 0; i < 32; ++i)
	{
		canvas_set(canvas, i, 0, b);
		canvas_set(canvas, i, 15, b);
	}

	for (int i = 0; i < 16; ++i)
	{
		canvas_set(canvas, 0, i, b);
		canvas_set(canvas, 31, i, b);
	}

	canvas_prnt(canvas);
	printf("\n");

	return 0;
}
