#include "LiczbaZespolona.hh"

std::ostream& operator<<(std::ostream& s, const LZ lz){
  s<<"("<<lz.Re() << std::showpos << lz.Im()<< std::noshowpos << "i)";
    return s;
    }
// Przeciazenie operatora wypisywania liczby zespolonej.
// Argumenty:
// -> klasa liczb zespolonych
// -> strumień wyjściowy, na który ma być wypisana liczba zespolona
// Zwracana wartość:
// -> strumień wyjściowy 

std::istream& operator>>(std::istream& input, LZ& lz){
    char temp;
    char temp2; // zmienne pomocnicza do przechowywania pobranych znakow 
    double Skladowa; // pomocnicza zmienna do przechowywania skladoych liczby zespolonej
    bool Blad=false; // zmienna pomocnicza do ustalenia, czy pod wzgledem formy liczba jest poprawna

    input>>temp; // pobranie pierwszego znaku z wejscia input

    if(temp!='(') return input; // jezeli pierwszy pobrany znak nie bedzie nawiasem, 
                                // przeciazenie zwraca strumien
    input>>temp; // po pobranym nawiasie otwierajacym pobierany jest kolejny znak 

    while (temp!='i'&& temp!=')'){
        if(isdigit(temp)||'+'||'-'){
            
            input>>temp2;
    
            if(temp2=='i'){
                input.putback(temp2);
                input.putback('1');
                input.putback(temp);
                input>>Skladowa;
                input>>temp;
                }
            else{
                if (isdigit(temp2)){
                    input.putback(temp2);
                    input.putback(temp); // jezeli pobrano znak liczbowy, zwroc pobrany 
                    input>>Skladowa; // pobranie i zapisanie w zmiennej typu double (Skladowa)// pobranie i sprawdzenie poprawnosci kolejnego znaku
                    input>>temp;}
                else{
                    if(!isdigit(temp)&&(temp2=='+'||temp2=='-')){
                        temp=temp2;
                        Blad=true;}
                    else{
                    if(!isdigit(temp2)&&(temp=='-'||temp=='+')){
                        temp=temp2;
                        input>>temp;
                        Blad=true;}
                    else{
                        input.putback(temp2);
                        input.putback(temp); // jezeli pobrano znak liczbowy, zwroc pobrany 
                        input>>Skladowa; // pobranie i zapisanie w zmiennej typu double (Skladowa)// pobranie i sprawdzenie poprawnosci kolejnego znaku
                        input>>temp;}}
                    }}} 
            else{
                input>>temp;
                Blad=true; }
        
        if(temp=='i') lz.Zmien_Im(Skladowa);
        else{
            if(temp=='+'||temp=='-'||temp==')'){
                lz.Zmien_Re(Skladowa);
                if(temp==')') lz.Zmien_Im(0);
                input.putback(temp);}
            else Blad=true;}

        input>>temp;
        } // pobranie i sprawdzenie kolejnego znaku

        if(Blad) input.setstate(input.failbit);
    return input;
}

LZ LZ::operator+(LZ lz1)
{
  lz1.re=lz1.re+(this->re);
  lz1.im=lz1.im+(this->im);

  return lz1;
}

LZ LZ::operator-(LZ lz1)
{

  lz1.im-=this->im;
  lz1.re-=this->re;
  return lz1;
}

double LZ::operator-(double liczba)
{
  double Temp;
  Temp=this->modul();

  return Temp-liczba;
}

double LZ::operator+(double liczba)
{
  double Temp;
  Temp=this->modul();

  return Temp+liczba;
}

LZ LZ::operator*(LZ lz1){
  /* przeciazenie operatora mnozenia dla liczb zespolonych */
  double Re, Im;
  
  Re=(lz1.re*(this->re))-(lz1.im*(this->im));
  Im=((this->im)*(lz1.re))+(lz1.im*(this->re));
  lz1.re=Re;
  lz1.im=Im;
  return lz1;
}

LZ LZ::operator*(double liczba)
{
  LZ Temp;
  Temp.re=(this->re)*liczba;
  Temp.im=(this->im)*liczba;

  return Temp;
}

LZ LZ::operator/(double liczba){
  /* przeciazenia operatora dzielenia dla dzielenia liczby */
  /* zespolonej przez liczbe rzeczywista                   */

  LZ lz1;
  lz1.re=(this->re)/liczba;
  lz1.im=(this->im)/liczba;

  return lz1;
}

LZ LZ::operator/(LZ lz1){
  /* przeciazenie operatora dzielenia dla dwoch liczb */
  /* zespolonych. */
  LZ temp=(*this);
  return ((lz1.sprzezenie())*(temp)/(lz1.modul_kwadrat()));
}

LZ &LZ::operator= (double liczba)
{
  (this->re)=liczba;
  (this->im)=0;
  return (*this);
}

LZ LZ::sprzezenie() const{
  /* funkcja sprzezenie: funkcja zwracajaca */
  /* sprzezenie podanej liczby zespolonej   */
  LZ lz1;
  lz1=(*this);
  lz1.im=((lz1.im)*(-1));
  return lz1;
}

double LZ::modul_kwadrat() const
{
  /* funkcja modul: funkcja zwracajaca */
  /* modul liczby zespolonej           */
  /* typ zwracanej wartości: double    */
  return potega_kwadrat(this->re)+potega_kwadrat(this->im);
}

double LZ::modul() const
{
  double Temp;
  Temp=(potega_kwadrat(this->re)+potega_kwadrat(this->im));
  return sqrt(Temp);
}

double LZ::potega_kwadrat(double liczba) const
{
  /* funkcja potega: funkcja zwracajaca  */
  /* kwadrat podanej liczby rzeczywistej */
  /* typ zwracanej wartości: double      */
  return liczba*liczba;
}

bool LZ::operator==(LZ& lz1){
  return ((lz1.re==this->re)&&(lz1.im==this->im));
}

bool LZ::operator!=(double liczba)
{
  return ((this->re)!=liczba)||((this->im)!=0);
}

bool LZ::operator==(double liczba)
{
  return ((this->re)==liczba)&&((this->im)==0);
}

bool LZ::operator<(double liczba)
{
  double Temp;
  Temp=this->modul();
  return Temp<liczba;
}

bool LZ::operator<(LZ lz1)
{
  double Temp, Temp2;
  
  Temp=this->modul();
  Temp2=lz1.modul();

  return Temp<Temp2;
}
