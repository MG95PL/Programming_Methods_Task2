#pragma once
#include "adres.h"
class Tperson
{
public:
	friend std::ostream& operator<< (std::ostream& out, const Tperson& ob);

	Tperson() : address(new Taddress()), name("none"), surname("none"), age(0) {}
	Tperson(const std::string& localName, const std::string& localSurname, int localAge, const Taddress& localAddress) : address(new Taddress(localAddress)), name(localName), surname(localSurname), age(localAge) {}
	Tperson(const Tperson& Lobject) : address(new Taddress(*Lobject.address)), name(Lobject.name), surname(Lobject.surname), age(Lobject.age) {}
	~Tperson() { delete address; }

	Tperson& operator=(const Tperson& person);
	
private:
	Taddress* address;
	std::string name, surname;
	int age;
};

