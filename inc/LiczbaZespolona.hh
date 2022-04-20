#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <cmath>

class LZ{
  private:
  // Pola przechowujace dane
  double re;
  double im;

  public:
  // Funkcje zwracajace poszczegolne pola
  double& Re(){return this->re;}
  double& Im(){return this->im;}
  double Re() const {return this->re;}
  double Im() const {return this->im;}

  // Metody zmieniajace poszczegolne pola,
  // Argumentem jest zmienna typu double
  void Zmien_Re(double liczba){this->re=liczba;}
  void Zmien_Im(double liczba){this->im=liczba;}
  
  // Operatory
  LZ operator+(LZ& lz1);
  LZ operator-(LZ& lz1);
  LZ operator*(LZ lz1);
  LZ operator* (double liczba);
  LZ operator/(double liczba);
  LZ operator/(LZ& lz1);
  LZ& operator= (double liczba);
  LZ sprzezenie(LZ& lz1);
  double modul_kwadrat();
  double modul();
  double potega_kwadrat(double liczba);
  bool operator==(LZ& lz1);
  bool operator==(double liczba);
  bool operator!=(double liczba);
  bool operator<(double liczba);
  bool operator<(LZ lz1);
};

std::istream& operator>>(std::istream& input, LZ& lz);

std::ostream& operator<<(std::ostream& s, const LZ lz);
