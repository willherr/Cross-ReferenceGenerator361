default: 
	gcc queue.h list.h
	gcc -c queue.c list.c proj2.c
	gcc -o main queue.o list.o proj2.o
	./main test.c test.o
