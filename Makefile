CXXFLAGS= -c -g -std=c++11 -iquote inc -Wall -pedantic
TRGDIR=/tmp/bk/test_swektora
OBJ=/tmp/bk/test_swektora/obj

__start__: ${TRGDIR}/test_wektora
	${TRGDIR}/test_wektora 1>plik.txt 0>plik.txt 2>log.txt

${OBJ}:
	mkdir -p ${OBJ}

${TRGDIR}/test_wektora: ${OBJ} ${OBJ}/main.o ${OBJ}/LiczbaZespolona.o
	g++ -o ${TRGDIR}/test_wektora ${OBJ}/main.o ${OBJ}/LiczbaZespolona.o

${OBJ}/main.o: src/main.cpp inc/SWektor.hh inc/SMacierz.hh inc/SUkladRownan.hh
	g++ -c ${CXXFLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/LiczbaZespolona.o: src/LiczbaZespolona.cpp
	g++ -c ${CXXFLAGS} -o ${OBJ}/LiczbaZespolona.o src/LiczbaZespolona.cpp
