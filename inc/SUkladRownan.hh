#ifndef SUKLAD_ROWNAN_HH
#define SUKLAD_ROWNAN_HH

#include "SMacierz.hh"
#include "SWektor.hh"
#include "rozmiar.h"
#include "LiczbaZespolona.hh"

template <typename STypA, typename STypb, typename SPole>
class SUkladRownanLiniowych {

  STypA A; // Macierz współczynników przy niewiadomych układu równań
  STypb b;  // Wektor przechowujący wyrazy wolne
  
  public:
  STypA& getA() {return (this->A);}
  STypA getA() const {return (this->A);}
  STypb& getb() {return (this->b);}
  STypb getb() const {return (this->b);}

  bool Solve(STypb& X);

  double Blad(const STypb X) const;

};

template <typename STypA, typename STypb, typename SPole>
std::istream& operator >> (std::istream &input, SUkladRownanLiniowych<STypA, STypb, SPole>& UklRown){

    for(uint i=0; i<ROZMIAR; ++i){
        for(uint j=0; j<ROZMIAR; ++j) input>>(UklRown.getA())(i, j);
    }

    (UklRown.getA()).Transpose();

    for(uint i=0; i<ROZMIAR; ++i) input>>(UklRown.getb())[i];

    return input;
}

template <typename STypA, typename STypb, typename SPole>
std::ostream& operator << ( std::ostream  &output, const SUkladRownanLiniowych<STypA, STypb, SPole> UklRown){

    for(uint i=0; i<ROZMIAR; ++i) output<<(UklRown.getA())[i]<<" "<<(UklRown.getb())[i]<<std::endl;

    return output;
}

template <typename STypA, typename STypb, typename SPole>
bool SUkladRownanLiniowych<STypA, STypb, SPole>::Solve(STypb& X)
{
    STypA Temp; // Tymczasowa zmienna do przechowywania macierzy z zamienioną kolumną

    SPole W; // Zmienna pomocnicza do przechowywania wartości wyznacznika głównego rozp. UR
    SPole W1; // Zmienna pomocnicza do przechowywania wartości wyznacznika

    W=(this->getA()).Wyznacznik(); // Wyliczenie głównego wyznacznika
    std::cout << " Wyznacznik glowny: " << W << std::endl;

    for(uint i=0; i<ROZMIAR; ++i){
        Temp=(this->A).ZamianaKol(i, (this->b));
        W1=Temp.Wyznacznik();

        std::cout << "Wyznacznik " << i+1 << " " << W1 << std::endl;

        if(W!=0) X[i]=W1/W;
        else {return false;}
    }

    return true;
}

template <typename STypA, typename STypb, typename SPole>
double SUkladRownanLiniowych<STypA, STypb, SPole>::Blad(const STypb X) const
{
    STypb Temp;
    Temp=(this->A)*X-(this->b);
    return Temp.modul();
}

#endif