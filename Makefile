CXX = /usr/bin/g++

main: main.o Button.o BubbleSort.o
	$(CXX) main.o Button.o BubbleSort.o -o main -L/usr/lib/x_86_64-linux-gnu -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	$(CXX) -c main.cpp -I/usr/include

Button.o: Button.cpp
	$(CXX) -c Button.cpp -I/usr/include

BubbleSort.o: BubbleSort.cpp
	$(CXX) -c BubbleSort.cpp -I/usr/include

clean: 
	$(RM) *.o

distclean: clean
	$(RM) main

run:
	./main
