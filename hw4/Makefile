all: mymalloc
mymalloc: mymalloc.c
	gcc -c -o funnyTest.o funnyTest.c
	gcc -c -o mymalloc.o mymalloc.c
	gcc  -fsanitize=address -o  test mymalloc.o funnyTest.o