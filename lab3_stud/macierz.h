#pragma once
#include <iostream>
using std::ostream;


class macierz {
	    static const int N=10;	//więcej o polach static będzie na w4
		double	t[N][N] = { 0 };
		int		n;				//bieżący wymiar macierzy

	public:
		// zdefiniuj tylko niezbędne elementy dla klasy (wykorzystane w funkcji main)
		// metody, funkcje zaprzyjaźnione, przeciążenia operatorów, itp

		macierz(int n);
		macierz(int n, double k);

		void losowa(double low, double high);

		macierz transpozycja();

		friend ostream& operator<<(ostream& out, const macierz& z);
};


