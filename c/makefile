qsp: readCSV.o qsp.o iqsort.o main.o
	gcc readCSV.o qsp.o iqsort.o main.o -o qsp -lm

readCSV.o: readCSV.c
	gcc -O3 -c readCSV.c

qsp.o: qsp.c
	gcc -O3 -c qsp.c

iqsort.o: iqsort.c
	gcc -O3 -c iqsort.c

main.o: main.c
	gcc -O3 -c main.c
