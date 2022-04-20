#ifndef SOPERACJE_HH
#define SOPERACJE_HH

#include <iostream>
#include "LiczbaZespolona.hh"

template <typename STyp>
STyp modul (STyp Liczba)
{
    if(Liczba<0) return (-1)*Liczba;
    else return Liczba;
}

#endif