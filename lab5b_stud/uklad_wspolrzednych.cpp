#include <iostream>
#include <algorithm>
#include "sygnal.h"
#include "uklad_wspolrzednych.h"
using namespace std;

//do uzupełnienia

uklad_wspolrzednych::uklad_wspolrzednych(sygnal_cyfrowy* sygnal)
	: sygnaly{ nullptr }, liczba_sygnalow{ 0 }, wiersze{ 0 }, kolumny{ 0 }, wykres{ nullptr }
{
	if (sygnal)
	{
		sygnaly = new sygnal_cyfrowy * [1];

		sygnaly[liczba_sygnalow++] = sygnal;
		kolumny = sygnal->get_liczba_probek();

		min_val = *min_element(sygnal->get_probki(), sygnal->get_probki() + sygnal->get_liczba_probek());
		int max = *max_element(sygnal->get_probki(), sygnal->get_probki() + sygnal->get_liczba_probek());
		wiersze = max - min_val + 1;

		wykres = new char* [wiersze];
		for (int i = 0; i < wiersze; ++i)
		{
			wykres[i] = new char[kolumny+1];
			memset(wykres[i], ' ', kolumny);
			wykres[i][kolumny] = '\0';
		}

		for(int i = 0; i < sygnal->get_liczba_probek(); ++i)
		{
			int value = sygnal->get_probki()[i];
			wykres[value - min_val][i] = '*';
		}
	}
}

uklad_wspolrzednych::~uklad_wspolrzednych()
{
	delete[] sygnaly;
	delete_wykres();
}

void uklad_wspolrzednych::add(sygnal_cyfrowy* sygnal)
{
	sygnal_cyfrowy** new_sygnaly = new sygnal_cyfrowy* [liczba_sygnalow + 1];
	std::memcpy(new_sygnaly, sygnaly, liczba_sygnalow * sizeof(sygnal_cyfrowy*));
	delete[] sygnaly;
	sygnaly = new_sygnaly;

	sygnaly[liczba_sygnalow++] = sygnal;

	delete_wykres();

	kolumny = sygnal->get_liczba_probek() > kolumny ? sygnal->get_liczba_probek() : kolumny;

	int min = *min_element(sygnal->get_probki(), sygnal->get_probki() + sygnal->get_liczba_probek());
	int max = *max_element(sygnal->get_probki(), sygnal->get_probki() + sygnal->get_liczba_probek());

	min_val = min < min_val ? min : min_val;
	max_val = max > max_val ? max : max_val;

	wiersze = max_val - min_val + 1;

	wykres = new char* [wiersze];
	for (int i = 0; i < wiersze; ++i)
	{
		wykres[i] = new char[kolumny + 1];
		memset(wykres[i], ' ', kolumny);
		wykres[i][kolumny] = '\0';
	}

	for(int j = 0; j < liczba_sygnalow; ++j)
	{
		for (int i = 0; i < sygnaly[j]->get_liczba_probek(); ++i)
		{
			int value = sygnaly[j]->get_probki()[i];
			wykres[value - min_val][i] = '*';
		}
	}
}

void uklad_wspolrzednych::delete_wykres()
{
	for (int i = 0; i < wiersze; ++i)
		delete[] wykres[i];

	delete[] wykres;

	wykres = nullptr;
}

ostream& operator<<(ostream& out, const uklad_wspolrzednych& uklad)
{
	for (int i = 0; i < uklad.kolumny; ++i)
		out << '-';
	out << '\n';
	for (int i = uklad.wiersze - 1; i >= 0; i--)
		out << uklad.wykres[i] << '\n';

	for (int i = 0; i < uklad.kolumny; ++i)
		out << '-';
	
	return out;
}
