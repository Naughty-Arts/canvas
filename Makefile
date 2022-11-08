test: main.c lib/canvas.h
	gcc -std=c2x -o build/test.exe main.c -L./lib -I"C:\\libs" -L"C:\\libs"

lib/canvas.h: canvas.h
	cp canvas.h lib/canvas.h

install: lib/canvas.h
	cp lib/canvas.h "C:\\libs\canvas.h"
