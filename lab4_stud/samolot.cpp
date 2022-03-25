#include "samolot.h"

//implementacja klasy Samolot

int Samolot::ilosc_samolotow_w_powietrzu = 0;
int Samolot::max_id = 0;

Samolot::Samolot()
	: id{ ++max_id }, ilosc_startow{0}, ilosc_pasazerow{0}, status{ GOTOWY }, port_docelowy{ "port nieznany" }
{
}

void Samolot::przygotuj_do_startu(int wysiada, int wsiada, const char* port)
{
	ilosc_pasazerow -= wysiada;
	if (ilosc_pasazerow < 0) ilosc_pasazerow = 0;
	ilosc_pasazerow += wsiada;

	strcpy_s(port_docelowy, port);

	status = GOTOWY;
}

int Samolot::start()
{
	static int startow_ogolem;

	if(status == GOTOWY)
	{
		status = ODLECIAL;
		ilosc_startow++;
		ilosc_samolotow_w_powietrzu++;
		startow_ogolem++;
	}

	return startow_ogolem;
}

void Samolot::laduj()
{
	if(status == ODLECIAL)
	{
		status = WYLADOWAL;
		ilosc_samolotow_w_powietrzu--;
	}
}

ostream& operator<<(ostream& out, const Samolot& samolot)
{

	out << "Samolot nr " << samolot.id << " do " << samolot.port_docelowy << " z " << samolot.ilosc_pasazerow << " pasazerami na pokladzie ";
	switch (samolot.status)
	{
	case Samolot::GOTOWY:
		out << "przygotowany do startu";
		break;
	case Samolot::ODLECIAL:
		out << "odlecial";
		break;
	case Samolot::WYLADOWAL:
		out << "wyladowal";
		break;
	}
	return out;
}

int Samolot::pobierz_starty() const
{
	return ilosc_startow;
}

int Samolot::pobierz_ilosc_w_powietrzu() const
{
	return ilosc_samolotow_w_powietrzu;
}



















