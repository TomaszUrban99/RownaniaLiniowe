#ifndef SWEKTOR_HH
#define SWEKTOR_HH


#include <iostream>



template <typename STyp, int SWymiar>
class SWektor {
    STyp  tab[SWymiar];
  public:
    SWektor() { for (STyp &Wsp: tab) Wsp = 0; }
  
    STyp  operator [] (unsigned int Ind) const { return tab[Ind]; }
    STyp &operator [] (unsigned int Ind)       { return tab[Ind]; }

    SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &Odjemnik) const;
    SWektor<STyp,SWymiar> operator * (double Mnoznik) const;
};




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
