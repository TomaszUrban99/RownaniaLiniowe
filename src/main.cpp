#include "SWektor.hh"
#include "SMacierz.hh"
#include "SUkladRownan.hh"
#include "LiczbaZespolona.hh"
#include "rozmiar.h"
#include <fstream>
#include <iomanip>
using namespace std;

typedef SWektor<LZ, ROZMIAR> WektZesp;
typedef SWektor<double, ROZMIAR> WektRz;

int main(int argc, char** argv)
{ 
  ifstream input(argv[1]);
  if(input.fail())
  {
    cerr << "Blad: nie podano prawidlowego pliku " << endl;
    return -1;
  }

  char Temp; // zmienna do przechowywania "identyfikatora"
  input>>Temp;

  if(Temp=='z')
  {
    WektZesp  Xz;
    SUkladRownanLiniowych< SMacierz< WektZesp, LZ, ROZMIAR >, WektZesp, LZ> UklRownZ; 
    input>>UklRownZ;
    
    if(input.fail())
    {
      cerr<< " Blad odczytu " << endl;
      return -1;
    }


    UklRownZ.Solve(Xz);
    cout << "Rozwiazanie rownania zespolonego: " << endl;
    cout << fixed << setprecision (2) << Xz << endl;
  }
  else{
  if(Temp=='r')
  {
    WektRz Xr;
    SUkladRownanLiniowych< SMacierz< WektRz, double, ROZMIAR >, WektRz, double> UklRownRz;
    input>>UklRownRz;
     if(input.fail())
    {
      cerr<< " Blad odczytu " << endl;
      return -1;
    }
    
    UklRownRz.Solve(Xr);
    cout << "Rozwiazanie rownania rzeczywistego: " << endl;
    cout << fixed << setprecision(2) << Xr << endl;
  }
  else
  {
    cerr << " Bledny format danych " << endl;
    return -1; 
  }}

  return 0;




}