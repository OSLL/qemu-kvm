all: vmcontrol.o create.o list.o destroy.o help.o suspend.o resume.o
	gcc *.o -o vmcontrol -lvirt

vmcontrol.o: vmcontrol.c vmcontrol.h
	gcc -c vmcontrol.c

create.o: ./create/create.c ./create/create.h
	gcc -c ./create/create.c

list.o: ./list/list.c ./list/list.h
	gcc -c ./list/list.c

destroy.o: ./destroy/destroy.c ./destroy/destroy.h
	gcc -c ./destroy/destroy.c

help.o: ./help/help.c ./help/help.h
	gcc -c ./help/help.c

suspend.o: ./suspend/suspend.c ./suspend/suspend.h
	gcc -c ./suspend/suspend.c

resume.o: ./resume/resume.c ./resume/resume.h
	gcc -c ./resume/resume.c

clean:
	rm -rf *.o vmcontrol
