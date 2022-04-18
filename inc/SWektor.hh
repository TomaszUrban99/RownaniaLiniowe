#ifndef SWEKTOR_HH
#define SWEKTOR_HH


#include <iostream>
#include <cmath>


template <typename STyp, int SWymiar>
class SWektor {
    STyp  tab[SWymiar];
  public:
    SWektor() { for (STyp &Wsp: tab) Wsp = 0; }
  
    STyp  operator [] (unsigned int Ind) const { return tab[Ind]; }
    STyp &operator [] (unsigned int Ind)       { return tab[Ind]; }

    SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &Odjemnik) const;
    SWektor<STyp,SWymiar> operator * (double Mnoznik) const;
    SWektor<STyp,SWymiar> operator + (const SWektor<STyp, SWymiar> &Wektor2) const;
    SWektor<STyp,SWymiar> operator / (double Dzielnik) const;

    double operator * (const SWektor<STyp,SWymiar> Wektor2) const;
    double modul() const;
};

template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar> SWektor<STyp, SWymiar>::operator +(const SWektor<STyp, SWymiar> & Wektor2) const
{
  SWektor<STyp, SWymiar> Wynik;

  for(unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] + Wektor2[Ind];
  return Wynik;

}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> &Odjemnik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] - Odjemnik[Ind];
  return Wynik;
}


template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (double Mnoznik) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind]*Mnoznik;
  return Wynik;  
}

template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar> SWektor<STyp,SWymiar>::operator / (double Dzielnik) const
{
  SWektor<STyp,SWymiar> Wynik;
  
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind]/Dzielnik;
  return Wynik;
}

template <typename STyp, int SWymiar>
double SWektor<STyp, SWymiar>::operator * (const SWektor<STyp,SWymiar> Wektor2) const
{
  double Wynik = 0;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik = Wynik + ((*this)[Ind] * Wektor2[Ind]);
  return Wynik;
}

template <typename STyp, int SWymiar>
double SWektor<STyp,SWymiar>::modul() const
{
  double Temp=0;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Temp = Temp + ((*this)[Ind] * (*this)[Ind]);
  return sqrt(Temp);
}

template <typename STyp, int SWymiar>
std::istream& operator >> (std:: istream &input, SWektor<STyp, SWymiar>& W)
{
  for(unsigned int Ind=0; Ind< SWymiar; ++Ind) input>>W[Ind];
  return input;
}

template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &output, const SWektor<STyp,SWymiar>& W)
{
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) {
    output<< " " << W[Ind];
  }  
  return output;
}

#endif
