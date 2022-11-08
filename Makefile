test: main.c lib/canvas.h lib/libcanvas.a
	gcc -std=c2x -o build/test.exe main.c -L./lib -lcanvas -I"C:\\libs" -L"C:\\libs"

lib/canvas.h: canvas.h
	cp canvas.h lib/canvas.h

lib/libcanvas.a: canvas.c canvas.h
	gcc -std=c2x -c canvas.c -o bin/canvas.o -I"C:\\libs" -L"C:\\libs"
	ar rcs lib/libcanvas.a bin/canvas.o

install: lib/canvas.h lib/libcanvas.a
	cp lib/canvas.h "C:\\libs\canvas.h"
	cp lib/libcanvas.a "C:\\libs\libcanvas.a"
