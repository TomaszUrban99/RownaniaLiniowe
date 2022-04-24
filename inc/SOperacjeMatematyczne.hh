#ifndef SOPERACJE_HH
#define SOPERACJE_HH

#include <iostream>
#include "LiczbaZespolona.hh"

template <typename STyp>
STyp modul (STyp Liczba)
{
    if(Liczba<0) return ((Liczba)*(-1));
    else return Liczba;
}

#endif