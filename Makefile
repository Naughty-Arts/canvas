
test: main.c lib/canvas.h lib/libcanvas.a
	gcc -std=c2x -o build/test.exe main.c -L"./lib" -L"C:\\libs" -I"C:\\libs" -lcanvas -lcolor

lib/canvas.h: canvas.h
	cp canvas.h lib/canvas.h

lib/libcanvas.a: bin/canvas.o lib/canvas.h
	ar rcs lib/libcanvas.a bin/canvas.o

bin/canvas.o: canvas.c canvas.h
	gcc -std=c2x -c -o bin/canvas.o canvas.c -L"C:\\libs" -I"C:\\libs"

install: lib/canvas.h lib/libcanvas.a
	cp lib/canvas.h "C:\\libs\\canvas.h"
	cp lib/libcanvas.a "C:\\libs\\libcanvas.a"
