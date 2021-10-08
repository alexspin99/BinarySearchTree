# makefile
# To disable the gcov options use a # to comment out the
# following line and uncomment the line below it
#CC = g++ -fprofile-arcs -ftest-coverage
CC = g++

project02:  main.o  item.o  
	$(CC)  main.o item.o   -o project02

main.o:  main.cpp bstree.h
	$(CC) -c main.cpp

item.o:  item.cpp item.h
	$(CC) -c item.cpp

clean:
	rm *.o  *.gcda *.gcno *.gcov  project02




