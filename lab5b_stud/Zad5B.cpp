#include <iostream>
using namespace std;
#include <math.h>
#include "sygnal.h"
#include "uklad_wspolrzednych.h"

int main()
{
	
	cout << "===================== ETAP 1 =====================" << endl;

	// Konstruktor bezargumentowy
	sygnal_cyfrowy sygnal_1;
	// Konstruktor z sygna³em zerowym
	sygnal_cyfrowy* sygnal_2 = new sygnal_cyfrowy(10);
	// Konstruktor z sygna³em prostokatnym
	int s3[20] = {0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5};
	sygnal_cyfrowy sygnal_3(20,s3);
	// Konstruktor z sygna³em trójk¹tnym
	int s4[50] = { 0, 2, 4, 6, 8, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10,
				  -8, -6, -4, -2, 0, 2, 4, 6, 8, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4 };
	sygnal_cyfrowy sygnal_4(30, s4);
	// Konstruktor z sygna³em sta³ym
	int s5[25] = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };
	sygnal_cyfrowy sygnal_5(20, s5);

	cout << "Pusty sygnal - nic sie nie wyswietla" << endl;
	cout << sygnal_1 << endl;
	cout << "Sygnal zerowy - same zera" << endl;
	cout << *sygnal_2 << endl;
	cout << "Sygnal prostokatny" << endl;
	cout << sygnal_3 << endl;
	cout << "Sygnal trojkatny" << endl;
	cout << sygnal_4 << endl;

	cout << "Suma sygnalow sta³ego i trojkatnego" << endl;
	cout << (sygnal_5 += sygnal_4) << endl;

	cout << "Kolejne sygnaly powinny byc rozne (pierwsza liczba)" << endl;
	sygnal_cyfrowy sygnal_6;
	sygnal_6 = sygnal_5;
	sygnal_6.set_pierwsza_wartosc(100);
	cout << " I: " << endl << sygnal_5 << endl;
	cout << "II: " << endl << sygnal_6 << endl;
	
	int* p = sygnal_2->get_probki();
	delete sygnal_2;
	if (p[0] != 0) cout << "Etak 1 - OK" << endl;
	else cout << "Czegos jeszcze brakuje..." << endl;
	
	cout << endl;
	cout << "===================== ETAP 2 =====================" << endl;

	uklad_wspolrzednych uklad_1;
	uklad_wspolrzednych uklad_2 (&sygnal_3);

	cout << "Pusty wykres - nic sie nie rysuje" << endl;
	cout << uklad_1 << endl;
	cout << "Wykres sygnalu prostokatnego" << endl;
	cout << uklad_2 << endl;
	cout << "Wykres dwoch sygnalow" << endl;
	uklad_2.add(&sygnal_4);
	cout << uklad_2 << endl;
	cout << "Wykres trzech sygnalow" << endl;
	sygnal_cyfrowy sygnal_p(25, s5);
	uklad_2.add(&sygnal_p);
	cout << uklad_2 << endl;

	return 0;
}