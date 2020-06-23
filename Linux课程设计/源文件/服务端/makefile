main: main.c mysql.o split.o thread_client.o
	gcc $^ -o $@ -lpthread -lmysqlclient -L/usr/lib64/mysql
mysql.o: mysql.c chat.h
	gcc -c $< -o $@
thread_client.o: thread_client.c chat.h
	gcc -c $< -o $@
split.o: split.c chat.h
	gcc -c $< -o $@
