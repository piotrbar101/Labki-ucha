#pragma once
#include <iostream> 
#include "sygnal.h"
using namespace std;

class uklad_wspolrzednych
{
private:
	sygnal_cyfrowy** sygnaly;	//dynamiczna tablica wskaŸników do sygna³ów
	int liczba_sygnalow;

	int wiersze;
	int kolumny;
	char** wykres;

public:
	uklad_wspolrzednych(sygnal_cyfrowy* sygnal = nullptr); //2 pkt
	~uklad_wspolrzednych(); //0.5 pkt

	void add(sygnal_cyfrowy* sygnal); //2.5 pkt

	friend ostream& operator<<(ostream&, const uklad_wspolrzednych&); //1 pkt

private:
	void delete_wykres();// metoda pomocnicza
	int min_val, max_val;
};