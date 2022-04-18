#ifndef SOPERACJE_HH
#define SOPERACJE_HH

#include <iostream>

template <typename STyp>
double modul (STyp Liczba)
{
    if(Liczba<0) return (-1)*Liczba;
    else return Liczba;
}

#endif