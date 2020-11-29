#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic

__start__: obroty_3D
	./obroty_3D

obroty_3D: obj obj/main.o obj/Prostopadloscian.o obj/Macierz3x3.o obj/Wektor3D.o\
           obj/lacze_do_gnuplota.o obj/dron.o obj/Bryla.o obj/Graniastoslup.o
	g++ -Wall -pedantic -std=c++0x -o obroty_3D obj/main.o obj/Wektor3D.o\
                        obj/Macierz3x3.o obj/Prostopadloscian.o obj/lacze_do_gnuplota.o\
  			obj/dron.o obj/Bryla.o obj/Graniastoslup.o
obj:
	mkdir obj

dat:
	mkdir dat

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/Prostopadloscian.hh inc/Macierz3x3.hh inc/Macierz.hh\
	   inc/Wektor3D.hh inc/Wektor.hh inc/Dron.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh\
         inc/Wektor3D.hh inc/Bryla.hh inc/Macierz3x3.hh
	g++ -c ${CXXFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Macierz3x3.o: src/Macierz3x3.cpp inc/Macierz3x3.hh inc/Macierz.hh inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Macierz3x3.o src/Macierz3x3.cpp

obj/Wektor3D.o: src/Wektor3D.cpp inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Wektor3D.o src/Wektor3D.cpp

obj/dron.o: src/Dron.cpp inc/Dron.hh inc/Macierz3x3.hh inc/lacze_do_gnuplota.hh\
	   inc/Graniastoslup.hh inc/Prostopadloscian.hh
	g++ -c ${CXXFLAGS} -o obj/dron.o src/Dron.cpp

obj/Bryla.o: src/Bryla.cpp inc/Bryla.hh inc/Wektor3D.hh inc/Macierz3x3.hh
	g++ -c ${CXXFLAGS} -o obj/Bryla.o src/Bryla.cpp

obj/Graniastoslup.o: src/Graniastoslup.cpp inc/Graniastoslup.hh inc/Wektor3D.hh inc/Bryla.hh
	g++ -c ${CXXFLAGS} -o obj/Graniastoslup.o src/Graniastoslup.cpp

clean:
	rm -f obj/*.o obroty_3D
