rubiks: rub
	./rubiks

rub: rubiks.o main.o conio.o
	gcc -O3 -o rubiks rubiks.o main.o -g

rubiks.o: rubiks.c rubiks.h conio.h
	gcc -O3 -o rubiks.o -c rubiks.c -g
	
conio.o: conio.c conio.h
	gcc -O3 -o conio.o -c conio.c -g

main.o: main.c rubiks.h rubiks.h conio.h
	gcc -O3 -o main.o -c main.c -g