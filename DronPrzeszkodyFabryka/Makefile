CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: rotations_3D
	./rotations_3D

rotations_3D: obj obj/main.o obj/lacze_do_gnuplota.o
	g++ -Wall -g -pedantic -std=c++0x -o rotations_3D obj/main.o\
	            obj/lacze_do_gnuplota.o

obj:
	mkdir obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -g -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/Wektor.hh inc/Wektor3D.hh inc/Macierz.hh inc/Macierz3x3.hh inc/Prostopadloscian.hh inc/Graniastoslup.hh\
           inc/Wirnik.hh inc/Korpus.hh inc/Dron.hh inc/Obiektsceny.hh inc/Przeszkoda.hh inc/Scena.hh inc/Fabryka_obiektow.hh
	g++ -g -c ${CXXFLAGS} -o obj/main.o src/main.cpp

clean:
	rm -f obj/*.o rotations_3D