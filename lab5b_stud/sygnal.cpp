#include <iostream> 
#include "sygnal.h"
using namespace std;

//do uzupełnienia

sygnal_cyfrowy::sygnal_cyfrowy(int ilosc_probek, int* probki)
	: wartosc_probek{ nullptr }, liczba_danych{ ilosc_probek }
{
	if(ilosc_probek)
	{
		wartosc_probek = new int[ilosc_probek];

		if (probki)
			std::memcpy(wartosc_probek, probki, ilosc_probek * sizeof(int));
		else
			std::memset(wartosc_probek, 0, ilosc_probek * sizeof(int));
	}
}

sygnal_cyfrowy::~sygnal_cyfrowy()
{
	delete[] wartosc_probek;
}

sygnal_cyfrowy& sygnal_cyfrowy::operator+=(const sygnal_cyfrowy& other)
{
	if(liczba_danych >= other.liczba_danych)
	{
		for (int i = 0; i < other.liczba_danych; i++)
			wartosc_probek[i] += other.wartosc_probek[i];
	}
	else
	{
		int* new_array = new int[other.liczba_danych];
		std::memcpy(new_array, other.wartosc_probek, other.liczba_danych * sizeof(int));
		for (int i = 0; i < liczba_danych; i++)
			new_array[i] += wartosc_probek[i];

		liczba_danych = other.liczba_danych;
		delete[] wartosc_probek;
		wartosc_probek = new_array;
	}

	return *this;
}

sygnal_cyfrowy& sygnal_cyfrowy::operator=(const sygnal_cyfrowy& other)
{
	if (this == &other)
		return *this;

	liczba_danych = other.liczba_danych;
	int* new_array = new int[liczba_danych];
	std::memcpy(new_array, other.wartosc_probek, liczba_danych * sizeof(int));
	delete[] wartosc_probek;

	wartosc_probek = new_array;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const sygnal_cyfrowy& sygnal)
{
	out << '{';
	for (int i = 0; i < sygnal.liczba_danych; i++)
		out << ' ' << sygnal.wartosc_probek[i] << ' ';
	out << '}';

	return out;
}