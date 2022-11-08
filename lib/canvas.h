#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <color.h>
#include <stdio.h>

typedef struct
{
	int w;
	int h;
	c* d;
} canvas;

#define canvas_free(_canvas) free(_canvas->d); free(_canvas)
#define canvas_clear(_canvas, color) for (int y = 0; y < _canvas->height; ++i) { int offset = _canvas->w * y; for (int x = 0; x < _canvas->width; ++x) { _canvas->d[offset + x] = color; } }
#define canvas_at(N, _canvas, x, y) { c b = black; if (x < 0 || x >= _canvas->w) N = b; else if (y < 0 || y >= _canvas->h) N = b; else N = _canvas->d[y * _canvas->w + x]; }
#define canvas_set(_canvas, x, y, color) if (x >= 0 && x < _canvas->w && y >= 0 && y < _canvas->h) {\
											c result = { color.r, color.g, color.b, color.a };\
											if (result.r > 1) result.r = 1; if (result.r < 0) result.r = 0;\
											if (result.g > 1) result.g = 1; if (result.g < 0) result.b = 0;\
											if (result.b > 1) result.b = 1; if (result.b < 0) result.b = 0;\
											_canvas->d[y * _canvas->w + x] = result;\
										}
#define canvas_make(N, _w, _h) {N = malloc(sizeof(canvas)); size_t s = sizeof(c) * _w * _h; N->d = malloc(s); memset(N->d, 0, s); N->w = _w; N->h = _h;}

#define canvas_prnt(_canvas) for (int y = 0; y < _canvas->h; ++y) { for (int x = 0; x < _canvas->w; ++x) { c color; canvas_at(color, _canvas, x, y); cterm("#", color); } printf("\n"); }

#endif
