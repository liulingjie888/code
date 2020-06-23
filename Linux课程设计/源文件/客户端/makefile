main: main.c util.o read_thread.o
	gcc $^ -o $@ -lpthread
read_thread.o: read_thread.c chat.h
	gcc -c $< -o $@
util.o: util.c chat.h
	gcc -c $< -o $@
