main: functions.o main_prog.o libtest.so
	gcc -I ../include -o main functions.o main_prog.o -L . -ltest

functions.o: functions.c
	gcc -c -I ../include functions.c

main_prog.o: main_prog.c
	gcc -c -I ../include main_prog.c

functions2.o: functions2.c
	gcc -c -I ../include -fPIC functions2.c

functions3.o: functions3.c
	gcc -c -I ../include -fPIC functions3.c

libtest.so: functions2.o functions3.o
	gcc -shared -fPIC -o libtest.so functions2.o functions3.o

clean:
	rm -rf *.o main
