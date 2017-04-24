all: MPQmain.o scheduler.o
	g++ -w -o MPQ MPQmain.o -Wno-deprecated
	g++ -w -o scheduler scheduler.o -Wno-deprecated 

scheduler.o: scheduler.cpp
	g++ -c scheduler.cpp -Wno-deprecated

MPQmain.o: MPQmain.cpp
	g++ -c MPQmain.cpp -Wno-deprecated
clean:
	rm -f *.o
