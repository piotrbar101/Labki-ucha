#include "lotnisko.h"
#include <algorithm>
//implementacja klasy Lotnisko

int Lotnisko::max_id_lotniska = 0;

Lotnisko::Lotnisko()
	: id_lotniska{ ++max_id_lotniska }, ilosc_samolotow{ 0 }, samoloty{}
{
}

bool Lotnisko::operator+=(Samolot& samolot)
{
	if (ilosc_samolotow >= MAX_ILOSC_SAMOLOTOW)
		return false;

	samoloty[ilosc_samolotow++] = &samolot;
	samolot.laduj();
	return true;
}

bool Lotnisko::zezwol_na_start(Samolot& samolot)
{
	if (samolot.status != Samolot::GOTOWY)
		return false;

	samolot.start();
	std::remove(std::begin(samoloty), std::end(samoloty), &samolot);
	ilosc_samolotow--;

	return true;
}

void Lotnisko::przekieruj(Samolot& samolot, const char* port) const
{
	strcpy_s(samolot.port_docelowy, port);
}

ostream& operator<<(ostream& out, const Lotnisko& lotnisko)
{
	out << "Samolotow na lotnisku nr " << lotnisko.id_lotniska << ":\n";
	for (int i = 0; i < lotnisko.ilosc_samolotow; i++)
		out << i + 1 << ". " << *lotnisko.samoloty[i] << '\n';

	return out;
}

Samolot* Lotnisko::operator[](int i) const
{
	if (i >= ilosc_samolotow || i < 0)
		return nullptr;

	return samoloty[i];
}

int Lotnisko::pobierz_samoloty() const
{
	return ilosc_samolotow;
}

void Lotnisko::naprawa(Samolot& s)
{
	s.ilosc_startow = 0;
	s.ilosc_pasazerow = 0;
	strcpy_s(s.port_docelowy, "port nieznany");
	s.status = Samolot::GOTOWY;
}










   








