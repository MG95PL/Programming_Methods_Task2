#include "stdafx.h"
#include "osoba.h"


Tperson& Tperson::operator=(const Tperson& person)
{
	if (&person == this) return *this;
	else {
		delete address;
		address = new Taddress;
		*address = *(person.address);
		name = person.name;
		surname = person.surname;
		age = person.age;
		return *this;
	}
}
