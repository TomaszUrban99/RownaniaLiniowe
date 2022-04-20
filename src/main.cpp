#include "SWektor.hh"
#include "SMacierz.hh"
#include "SUkladRownan.hh"
#include "LiczbaZespolona.hh"
#include "rozmiar.h"
#include <fstream>

using namespace std;

int main()
{
     ifstream input("macierz.txt");

  cout << endl
       << " --------- Test klasy SUkladRownan---------------" << endl;
  
  SWektor<double,ROZMIAR>    W, W_wynik, X;
  double Wynik;
  uint liczba=0;
  SMacierz<SWektor<double, ROZMIAR>, double, ROZMIAR> M;
  SUkladRownanLiniowych< SMacierz<SWektor<double, ROZMIAR>, double, ROZMIAR>, SWektor <double, ROZMIAR>, double> UklRown;
  
  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    W[Ind] = Ind;
  }

  input>>UklRown;

  cout << " Wyswietlenie ukladu rownan: " << endl;
  cout << UklRown << endl;
  cout << endl;

  UklRown.Solve(X);

  cout << " Wyyswietlenie rozwiazania ukladu rownan: " << endl;
  cout << X << endl;
  cout << endl;


}
