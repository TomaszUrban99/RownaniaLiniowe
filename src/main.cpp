#include "SWektor.hh"
#include "SMacierz.hh"
#include "rozmiar.h"
#include <fstream>

using namespace std;

int main()
{
     ifstream input("macierz.txt");

  cout << endl
       << " --------- Test klasy SMacierzc---------------" << endl;
  
  SWektor<double,ROZMIAR>    W, W_wynik;
  double Wynik;
  uint liczba=0;
  SMacierz<SWektor<double, ROZMIAR>, double, ROZMIAR> M;
  
  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    W[Ind] = Ind;
  }

  input>>M;

  cout << " Wyswietlenie Macierzy: " << endl;
  cout << M << endl;
  cout << endl;

  cout << M.ZamianaKol(0, W);
  cout << endl;
  
  M.MaxWiersz(0, liczba);

  cout << " Wyznacznik Macierzy " << endl;
  cout << M.Wyznacznik() << endl;

  cout << " Wyswietlenie Macierzy po sortowaniu: " << endl;
  cout << M << endl;
  cout << endl;


}
