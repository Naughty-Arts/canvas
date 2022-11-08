#include "canvas.h"

#include <string.h>
#include <stdlib.h>

void canvas_to_ppm(FILE* ppm_file, canvas* canvas)
{
	fprintf(ppm_file, "P3\n");
	fprintf(ppm_file, "%d %d\n", canvas->w, canvas->h);
	fprintf(ppm_file, "255\n");
	for (int y = 0; y < canvas->h; ++y)
	{
		for (int x = 0; x < canvas->w; ++x)
		{
			c color = canvas->d[y * canvas->w + x];
			int r = color.r * 255;
			int g = color.g * 255;
			int b = color.b * 255;
			fprintf(ppm_file, "%d %d %d\n", r, g, b);
		}
	}
}