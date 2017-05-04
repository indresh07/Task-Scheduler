all: obj/MPQ_driver.o obj/scheduler.o
	g++ -w -o bin/MPQ_driver obj/MPQ_driver.o -Wno-deprecated
	g++ -w -o bin/scheduler obj/scheduler.o -Wno-deprecated 

obj/scheduler.o: src/scheduler.cpp
	g++ -c -o obj/scheduler.o src/scheduler.cpp -Wno-deprecated

obj/MPQ_driver.o: src/MPQ_driver.cpp
	g++ -c -o obj/MPQ_driver.o src/MPQ_driver.cpp -Wno-deprecated
clean:
	rm -f bin/*
	rm -f obj/*
