// ConsoleApplication15.cpp : Defines the entry point for the console application.
//

/*
*Task 2
*Define class person (name, surname, age, address).
*Address is an dynamic object of anther class 
*/


#include "stdafx.h"
#include "adres.h"
#include "osoba.h"

using namespace std;

ostream& operator<< (ostream& out, const Taddress& ob)
{
	out << ob.city << '\t' << ob.post_code << '\t' << ob.street << '\t' << ob.number << endl;
	return out;
}

ostream& operator<< (ostream& out, const Tperson& ob)
{
	out << ob.name << '\t' << ob.surname << '\t' << ob.age << '\t' << (*ob.address) << endl;
	return out;
}


int main()
try {
	cout << "Hello world" << endl;

#define osoba Tperson   //osoba is a person in polish 
#define adres Taddress  //adres is an adress in polish 

	//Under this line is a test code which, I`m not an owner. It has been created by Czêstochowa Uniwersity of Technology research associates

	adres* wsk = new adres("Czestochowa", "42-200", "Dabrowskiego", 73);	//(City,Post Code, Street, Number of street)
	cout << *wsk << '\n';
	adres a1(*wsk);
	delete wsk;

	const adres* wsk1 = new adres("Warszawa", "00-950", "Mysliwiecka", 357);
	cout << a1 << '\n';
	cout << *wsk1 << '\n';
	adres a2;
	cout << a2 << '\n';
	a2 = a1;
	cout << a2 << '\n';

	osoba o("Jan", "Kos", 25, *wsk1);	//(Name, Surname, Age, Taddress class pointer)
	delete wsk1;

	cout << o << '\n';
	osoba o1(o);
	cout << o1 << '\n';
	osoba o2;
	cout << o2 << '\n';
	o2 = o1;
	cout << o2 << '\n';

	//End of the test code

	system("pause");
	return 0;
}
catch (bad_alloc) { cerr << "Memory allocate error"; }