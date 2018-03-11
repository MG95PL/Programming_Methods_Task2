#include <iostream>
#include <string>


using namespace std;

class adres
{
  string miasto, kod, ulica;
  int numer;
  
public:
  
  adres(): miasto("brak"), kod("brak"), ulica("brak"), numer(0) {}
  adres(const string& mias, const string& ko, const string& ul, int num): miasto(mias), kod(ko), ulica(ul), numer(num) {}
  friend ostream& operator<< (ostream& out, const adres& ob);
  
};


class osoba
{
  adres* adr;
  string imie, nazwisko;
  int wiek;
   
  
public:
  
  osoba(): adr(new adres()), imie("brak"), nazwisko("brak"), wiek(0) {}
  osoba(const string& im,const string& naz, int wi, const adres& ad): adr(new adres(ad)), imie(im), nazwisko(naz), wiek(wi) {}
  osoba(const osoba& ob): adr(new adres(*ob.adr)), imie(ob.imie), nazwisko(ob.nazwisko), wiek(ob.wiek)  {}
  ~osoba() {delete adr;}
  
 
 osoba& operator=(const osoba& os)
  {
    if (&os == this) return *this;
    else { 
      delete adr;
      adr = new adres;
      *adr = *(os.adr);
      imie = os.imie;
      nazwisko = os.nazwisko;
      wiek = os.wiek;
      return *this;}
  }
  
  
  friend ostream& operator<< (ostream& out, const osoba& ob);
};

  ostream& operator<< (ostream& out, const adres& ob)
  {
   out << ob.miasto << '\t' << ob.kod << '\t' << ob.ulica << '\t' << ob.numer << endl;  
    return out;
  }
  
  ostream& operator<< (ostream& out, const osoba& ob)
  {
   out << ob.imie << '\t' << ob.nazwisko << '\t' << ob.wiek << '\t' << (*ob.adr) << endl;  
    return out;
  }


int main()
try{
  cout << "Hello world" << endl;
  

  //Under this line is a test code which, I`m not an owner. It has been created by Czêstochowa Uniwersity of Technology research associates

  adres* wsk = new adres("Czestochowa", "42-200", "Dabrowskiego", 73);
  cout << *wsk << '\n';
  adres a1(*wsk);
  delete wsk;
  
  const adres* wsk1 = new adres("Warszawa", "00-950","Mysliwiecka", 357); 
  cout << a1 << '\n'; 
  cout << *wsk1 << '\n'; 
  adres a2;
  cout << a2 << '\n'; 
  a2 = a1;
  cout << a2 << '\n';
  
  osoba o("Jan", "Kos", 25, *wsk1);
  delete wsk1;
  
  cout << o << '\n';
  osoba o1(o);
  cout << o1 << '\n'; 
  osoba o2; 
  cout << o2 << '\n'; 
  o2 = o1; 
  cout << o2 << '\n'; 

  //End of the test code
   
 return 0;  
} catch (bad_alloc) {cerr << "blad alokacji pamieci";}