#include "SWektor.hh"
#include "SMacierz.hh"
#include "SUkladRownan.hh"
#include "LiczbaZespolona.hh"
#include "rozmiar.h"
#include <fstream>
using namespace std;

int main()
{
  ifstream input("Ukl2.txt");

  cout << endl
       << " --------- Test klasy SUkladRownan---------------" << endl;
  
  SWektor<LZ,ROZMIAR>    W, W_wynik, X;
  LZ Z1, Z2;
  double Wynik;
  uint liczba=0;
  SMacierz<SWektor<LZ, ROZMIAR>, LZ, ROZMIAR> M;

  input>>Z1;
  input>>Z2;

  cout << "LZ 1" << Z1 << endl;
  cout << "LZ 2" << Z2 << endl;

  cout << "Wynik dzielenia: " << Z1/Z2 << endl;

  return 0;




}