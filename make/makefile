new.exe:	main.o addition.o subtraction.o multiplication.o division.o utils.o
	gcc -o new.exe main.o addition.o subtraction.o multiplication.o division.o utils.o

main.o:	main.c apc.h
	gcc -c main.c

addition.o:	addition.c apc.h
	gcc -c addition.c

subtraction.o:	subtraction.c apc.h
	gcc -c subtraction.c

multiplication.o:	multiplication.c apc.h
	gcc -c multiplication.c

division.o:	division.c apc.h
	gcc -c division.c
utils.o:	utils.c apc.h
	gcc -c utils.c

clean:	
	rm	*.exe	*.o