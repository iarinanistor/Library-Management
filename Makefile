
CFLAGS = -g -Wno-unused-parameter

all : main main1 test_plot

main : main.o biblioLC.o entreeSortieLC.o
	gcc -o main $(CFLAGS) main.o biblioLC.o entreeSortieLC.o

main1 : main1.o biblioH.o entreeSortieH.o
	gcc -o main1 $(CFLAGS) main1.o biblioH.o entreeSortieH.o

main.o : main.c biblioLC.h entreeSortieLC.h
	gcc $(CFLAGS) -c main.c

main1.o : main1.c biblioH.h entreeSortieH.h 
	gcc $(CFLAGS) -c main1.c

main_test.o : main_test.c biblioLC.h entreeSortieLC.h
	gcc $(CFLAGS) -c main_test.c

main_test : main_test.o biblioLC.o entreeSortieLC.o
	gcc -o main_test $(CFLAGS) main_test.o biblioLC.o entreeSortieLC.o

main1_test : main1_test.o biblioH.o entreeSortieH.o
	gcc -o main1_test $(CFLAGS) main1_test.o biblioH.o entreeSortieH.o

main1_test.o : main1_test.c biblioH.c entreeSortieH.c 
	gcc $(CFLAGS) -c main1_test.c

test_plot.o : test_plot.c biblioLC.h entreeSortieLC.h entreeSortieH.h biblioH.h
	gcc $(CFLAGS) -c test_plot.c

test_plot : test_plot.o biblioLC.o entreeSortieLC.o entreeSortieH.o biblioH.o
	gcc -o test_plot $(CFLAGS) test_plot.o biblioLC.o entreeSortieLC.o entreeSortieH.o biblioH.o
	
comparaison.o : comparaison.c biblioLC.h entreeSortieLC.h entreeSortieH.h biblioH.h
	gcc $(CFLAGS) -c comparaison.c
	
comparaison : comparaison.o biblioLC.o entreeSortieLC.o biblioH.o entreeSortieH.o

entreeSortieLC.o : entreeSortieLC.c entreeSortieLC.h biblioLC.h 
	gcc $(CFLAGS) -c entreeSortieLC.c

biblioLC.o : biblioLC.c biblioLC.h
	gcc $(CFLAGS) -c biblioLC.c
	
biblioH.o : biblioH.c biblioH.h
	gcc $(CFLAGS) -c biblioH.c
	
entreeSortieH.o : entreeSortieH.c entreeSortieH.h biblioH.h
	gcc $(CFLAGS) -c entreeSortieH.c
	
clean : 
	rm -f *.o main 
