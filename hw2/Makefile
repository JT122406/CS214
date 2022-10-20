all: ls find tree
ls: ls.c
	gcc -o ls -g -Wall -Wvla -fsanitize=address ls.c
find: find.c
	gcc -o find -g -Wall -Wvla -fsanitize=address find.c
tree: tree.c
	gcc -o tree -g -Wall -Wvla -fsanitize=address tree.c