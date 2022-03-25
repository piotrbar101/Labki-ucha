#include <iostream>
using namespace std;
#include "Data.h"


int main()
{
	cout << "----------   ETAP 1    -------------------------" << endl<<endl;

	Data d1;		// domyœlnie: 4 3 2022
	Data d2(7);		// 7 i domyœlnie: 3 2022
	Data d3(2, 8);	// 2 8 i domyœlne: 2022
	Data d4("30.12.2022");	// zakladamy poprawny format daty (tylko napisy w takim formacie)

	cout << "d1=" << d1 << endl;
	cout << "d2=" << d2 << endl;

	d3.UstawFormat(true);	//miesiac wypisywany jest s³ownie
	cout << "d3=" << d3 << endl;

	d4.UstawFormat(true);	//miesi¹c wypisywany jest s³ownie
	cout << "d4=" << d4 << endl;
	
	cout << "Podaj date: (2001<=rok<=2100)"<<endl;
	cin >> d1;
	cout << "podano d1= " << d1 << endl;

	cout << "----------   ETAP 2    -------------------------" << endl<<endl;
	/*
	d4 = d1;
	for (int i = 0; i < 6; i++)
	{
		d4.NastDzien();
		cout << "d4=" << d4 << endl;
	}
	*/
	
	cout << "----------   ETAP 3    -------------------------" << endl<<endl;
	/*
	for (int i = 0; i < 6; i++)
	{
		d4.PopDzien();
		cout << "d4=" << d4 << endl;
	}
	*/
	
	cout << "----------   ETAP 4    -------------------------" << endl<<endl;
	/*
	Data d5 = d4, d6;
	d5.WybranyDzien();
	cout << "za tydzien bedzie d5=" << d5 << endl;
	
	d5.WybranyDzien(14);
	cout << "i jeszcze za 2 tygodnie bedzie d5=" << d5 << endl;

	d6 = d5;
	d5.WybranyDzien(-21);
	cout << "a 3 tygodnie temu bylo d5=" << d5 << endl;
	*/
	
	cout << "----------   ETAP 5    -------------------------" << endl<<endl;
	/*
	if (d5.CzyRowne(d6))
		cout << "Daty: " << d5 << " oraz " << d6 << " takie same " << endl;
	else
		cout << "Daty: " << d5 << " oraz " << d6 << " inne " << endl;

	if (CzyMniejsza(d5,d6))
		cout << "Data: " << d5 << " jest wczesniej niz " << d6 << endl;
	*/
	
	cout << "----------   ETAP 6    -------------------------" << endl<<endl;
	/*
	d5.UstawFormat(true);
	d6.UstawFormat(true);
	cout << "Liczba dni od: " << d5<< " do "<< d6<< " wynosi: "<< LiczbaDni(d5, d6) << endl;

	d5.UstawFormat(false);
	d6.UstawFormat(false);
	cout << "Liczba dni od: " << d6 << " do " << d5 << " wynosi: " << LiczbaDni(d6, d5) << endl;
	cout << "Liczba dni od: " << d5 << " do " << d5 << " wynosi: " << LiczbaDni(d5, d5) << endl;
	*/

}