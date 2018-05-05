all: vmcontrol.o create.o list.o destroy.o
	gcc *.o -o vmcontrol -lvirt

vmcontrol.o: vmcontrol.c vmcontrol.h
	gcc -c vmcontrol.c

create.o: ./create/create.c ./create/create.h
	gcc -c ./create/create.c

list.o: ./list/list.c ./list/list.h
	gcc -c ./list/list.c

destroy.o: ./destroy/destroy.c ./destroy/destroy.h
	gcc -c ./destroy/destroy.c

clean:
	rm -rf *.o vmcontrol
