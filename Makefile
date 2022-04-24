CXXFLAGS= -c -g -std=c++11 -iquote inc -Wall -pedantic
TRGDIR=~/Programowanie_Obiektowe/szablon/test_swektora
OBJ=/tmp/bk/test_swektora/obj

__start__: ${TRGDIR}/test_wektora
	${TRGDIR}/test_wektora macierz.txt 1>plik.txt 
${OBJ}:
	mkdir -p ${OBJ}

${TRGDIR}/test_wektora: ${OBJ} ${OBJ}/main.o ${OBJ}/LiczbaZespolona.o
	g++ -o ${TRGDIR}/test_wektora ${OBJ}/main.o ${OBJ}/LiczbaZespolona.o

${OBJ}/main.o: src/main.cpp inc/SWektor.hh inc/SMacierz.hh inc/SUkladRownan.hh
	g++ -c ${CXXFLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/LiczbaZespolona.o: src/LiczbaZespolona.cpp
	g++ -c ${CXXFLAGS} -o ${OBJ}/LiczbaZespolona.o src/LiczbaZespolona.cpp
