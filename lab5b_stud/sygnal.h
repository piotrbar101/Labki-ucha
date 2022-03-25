#pragma once
#include <iosfwd>


class sygnal_cyfrowy
{
private:
	int* wartosc_probek;
	int liczba_danych;

public:
	int* get_probki() const { return wartosc_probek; }
	void set_pierwsza_wartosc(int x) { wartosc_probek[0] = x; }

	//do uzupełnienia
	sygnal_cyfrowy(int ilosc_probek = 0, int* probki = nullptr);
	~sygnal_cyfrowy();

	friend std::ostream& operator<<(std::ostream& out, const sygnal_cyfrowy& sygnal);
	sygnal_cyfrowy& operator+=(const sygnal_cyfrowy& other);
	sygnal_cyfrowy& operator= (const sygnal_cyfrowy& other);

	int get_liczba_probek() const { return liczba_danych; }
};