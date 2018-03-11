#pragma once
#include <string>
#include <iostream>

class Taddress
{
public:
	friend std::ostream& operator<< (std::ostream& out, const Taddress& ob);

	Taddress() : city("none"), post_code("none"), street("none"), number(0) {}
	Taddress(const std::string& Lcity, const std::string& Lpost_code, const std::string& Lstreet, int Lnumber) : city(Lcity), post_code(Lpost_code), street(Lstreet), number(Lnumber) {}
	
private:

	std::string city, post_code, street;
	int number;

};

