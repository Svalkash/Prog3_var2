#pragma once

#define DSZ 4
#define STRMAXLEN 1024

#define inmode 0 //0 - dialog/testing, 1 - application

#include <iostream>

namespace P3_3 {
	int hToD(const char);
	char dToH(const int);

	class Hex
	{
	private:
		//data
		int sign;
		int len;
		int sz;
		char *dig;
		//functions
		Hex &transform();
		void calcLen(); 
		void expand(int);
		void cut();
	public:
		//constr
		Hex();
		Hex(const int);
		Hex(const char *);
		Hex(const Hex &); //Hex C(A+B)
		Hex(Hex &&);
		//io
		friend std::istream &operator >>(std::istream &, Hex &);
		friend std::ostream &operator <<(std::ostream &, const Hex &);
		//operations
		const Hex operator +(const Hex &) const; 
		const Hex operator -(const Hex &) const;
		Hex &operator <<=(const int);
		Hex &operator >>=(const int);
		Hex &operator =(const Hex &);
		Hex &operator =(Hex &&);
		//info
		const bool operator ==(const Hex &) const;
		const bool operator <(const Hex &) const;
		const bool operator >(const Hex &) const;
		const bool isEven() const;
		//destr
		~Hex() { delete[] dig; }
		//get
		int getSign() const { return sign; }
		int getLen() const { return len; }
		int getSz() const { return sz; }
		char getDig(int i) const { return dig[i]; }
	};
}

